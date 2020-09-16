#include <iostream>
using namespace std;

class alloc{
};

template<class T,class Alloc=alloc>
class Vector{
public:
    typedef T value_type;
    typedef value_type* iterato;

    template<class I>
    void insert(iterato position, I first, I last){
        cout << "insert" << endl;
    }
};

int main()
{
    int ia[5] = {0,1,2,3,4};

    Vector<int> x;
    Vector<int>::iterato ite;
    x.insert(ite, ia, ia+5);
    return 0;
}

