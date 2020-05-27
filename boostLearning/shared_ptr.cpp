#include <boost/shared_ptr.hpp>
#include <iostream>
#include <assert.h>
class Foo{
private:
    std::string m_strName;
public:
    Foo(const std::string& strName):m_strName(strName){ }
    ~Foo(){
        std::cout << "Destructing Foo with name = " << m_strName << std::endl;
    }
};

typedef boost::shared_ptr<Foo> FooPtr;

void Test_Boost_Shared_Ptr(){
    //ptr1获得Foo_1指针的管理权
    FooPtr ptr1(new Foo("Foo1"));//引用计数为1
    assert(ptr1.use_count()==1);

    //ptr2指向ptr1
    FooPtr ptr2 = ptr1;//调用shared_ptr赋值操作符，引用计数加1
    assert(ptr1.use_count()==ptr2.use_count());
    assert(ptr1==ptr2);//相当于ptr1.get()==ptr2.get()
    assert(ptr1.use_count()==2);

    //ptr3获得Foo_1指针的所有权
    FooPtr ptr3 = ptr2;//引用计数加1
    assert(ptr1.use_count()==ptr2.use_count() && ptr1.use_count()==ptr3.use_count());
    assert(ptr1.use_count()==3 && ptr2.use_count()==3 && ptr3.use_count() ==3);
    assert(ptr1==ptr2 && ptr1==ptr3);

    //ptr3重置，测试reset函数
    ptr3.reset();
    assert(ptr3.use_count()==0 && ptr3.get()==NULL);
    std::cout << "ptr3引用计数为0，get函数指向NULL，但是不会调用析构函数，因为ptr1和ptr2都指向了原生指针" << std::endl;
    assert(ptr1.use_count()==ptr2.use_count() && ptr1.use_count() == 2);
    assert(ptr1 == ptr2 && ptr1 != ptr3);
    
}

int main(int argc, char const *argv[])
{
    Test_Boost_Shared_Ptr();
    return 0;
}
