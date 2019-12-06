
#include <iostream>
using namespace std;
class Cbook
{
private:
    char *m_pczName;
    int m_nPages;
    int m_nEdition;
public:
    void GetBookName(char *pName);
    int GetTotalPages();
    int GetBookEdition();
private:
    void SetBookName(char *pName);
    void SetTotalPages(int npages);
    void SetBookEdition(int nEdition);
public:
    Cbook();

};
void Cbook::GetBookName(char *pName){
    strcpy(pName, m_pczName);
}

int Cbook::GetTotalPages(){
    return m_nPages;
}

int Cbook::GetBookEdition(){
    return m_nEdition;
}

void Cbook::SetBookName(char *pName){
    if (m_pczName != 0)
        delete []m_pczName;

    m_pczName = new char[strlen(pName) + 1];
    strcpy(pName, m_pczName);
}

void Cbook::SetTotalPages(int npages){
    m_nPages = npages;
}

void Cbook::SetBookEdition(int nEdition){
    m_nEdition = nEdition;
}

class DATE{
public:
    DATE(int m,int d,int y);
    void print();
private:
    int month,day,year;
};

DATE dates[4] = {DATE(7, 7, 2001),DATE(7, 8, 2001),DATE(7, 9, 2001),DATE(7, 10, 2001)};

DATE::DATE(int m,int d,int y){
    month = m;
    day = d;
    year = y;
}

void DATE::print(){
    std::cout<<month<<"\t"<<day<<"\t"<<year<<"\t"<<std::endl;
}

class Complex{
private:
    double real,imag;
public:
    Complex(double r,double i);
    void disp(){
        std::cout<<real<<"+"<<imag<<"i"<<std::endl;
    }

};
Complex::Complex(double r,double i){
    real = r;
    imag = i;
}

class myClass{
private:
    int a;
public:
    myClass();
    void disp(){
        std::cout<<"a * a = "<<a*a<<std::endl;
    }
};

myClass::myClass(){
    std::cout<<"初始化完成"<<endl;
    a = 10;
}

int main(){
    
    myClass op1;
    op1.disp();

    
}
