#include <iostream>
#include <thread>

using namespace std;

void f(int i,std::string const& s);

void oops(int some_param)
{
    // 此种情况下，buffer的指针被传递给现场作为参数，oops退出时，会导致未定义的行为。
    char buffer[1024];
    sprintf(buffer,"%i",some_param);
    std::thread t(f,3,buffer);
    t.detach();
}

void not_oops(int some_param)
{
    
    char buffer[1024];
    sprintf(buffer,"%i",some_param);
    std::thread t(f,3,std::string(buffer)); // 使用std::string 避免悬浮指针,存在转换
    t.detach();
}



// 窗口功能伪代码
void update_data_for_widget(widget_id w,widget_data& data);

void oops_again(widget_id w){
    widget_data data;
    std::thread t(update_data_for_widget,w,data);  // thread构造函数并不知道你想传入引用，而是复制了所提供的值，所以线程结束后，所有更改都被舍弃。
    display_status();
    t.join();
    process_widget_data(data);
} 
// 解决方法：在创建thread时，使用std::ref来包装需要被引用的参数。   std::thread t(update_data_for_widget,w,std::ref(data));

class X
{
public:
    void do_lengthy_work();
};



// 这里的参数不能被复制，只能被移动。
void process_big_object(std::unique_ptr<big_object>);

int main()
{
    X my_x;
    std::thread t(&X::do_lengthy_work,&my_x); // 传递一个成员函数的指针作为函数，提供一个合适的对象指针作为第一个参数，之后的参数为成员函数的参数列表
    

    std::unique_ptr<big_object> p(new big_object);
    p->prepare_data(42);
    std::thread t(process_big_object,std::move(p));
    return 0;
}

