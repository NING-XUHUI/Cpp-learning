#include<iostream>
#include<thread>

using namespace std;

void do_something(){
    cout << "do something" << endl;
}

void do_something_else(){          
    cout << "do something else" << endl;
}

class background_task{
public:
    void printSomething(){
        cout << "print something" << endl;
    } 
    void operator ()()const{
        do_something();
        do_something_else();
    }
    
};

int main(){
    std::thread my_thread([]{
        do_something();
        do_something_else();
                          });
    my_thread.join();
    return 0;
}
