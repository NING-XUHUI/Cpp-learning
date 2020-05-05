#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

class A{
public:
    int m_i;
    A(int a):m_i(a){
        cout << "A::A(int a) " << std::this_thread::get_id() << endl;
    }
    A(const A& a):m_i(a.m_i){
        cout << "A::A(const A& a) " << std::this_thread::get_id() << endl;
    }
    ~A() {
        cout << "~A() " << std::this_thread::get_id() << endl;
    }
};

void my_print1(const int i,const string& pmyprint){
    cout << i << endl;
    cout << pmyprint.c_str() << endl;
}

void my_print2(const int i,const A& my_A){

    cout << my_A.m_i << endl;
}

int main(int argc, char const *argv[])
{
    int mvar = 1;
    A a(12);
    thread my_t2(my_print1,mvar,A(12));
    return 0;
}
