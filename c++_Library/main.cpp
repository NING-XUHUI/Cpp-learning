#include <iostream>
#include "Book.h"
int main() {

    Book book1("NING",30.9,"XUHUI");

    double a = book1.getPrice();
    std::cout<<a;
    return 0;
}
