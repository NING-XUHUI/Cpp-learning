#include <iostream>
#include <thread>

//局部变量buffer的指针被传递到新线程
void f(int i,const std::string& s);
void oops(int some_param){
    char buffer[1024];
    sprintf(buffer,"%i",some_param);
    //std::thread t(f,3,buffer);
    std::thread t(f,3,std::string(buffer));
    t.detach();
}

void update_data_for_widget(widget_id w,widget_data& data);

void oops_again(widget_id w){
    widget_data data;
    //std::thread t(update_data_for_widget,w,data);//update_data_for_widget想传入的是引用，而此处传入复制数据，未能满足需求
    std::thread t(update_data_for_widget,w,std::ref(data));
    display_status();
    t.join();
    process_widget_data(data);
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

