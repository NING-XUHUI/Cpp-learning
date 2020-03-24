//
// Created by 宁旭晖 on 2020/3/24.
//

#include "Book.h"

inline
double Book::getPrice()const {
    return price;
}

inline
std::string Book::getName()const{
    return name;
}

inline
std::string Book::getWriter()const{
    return writer;
}
void Book::setPrice(double &newPrice){
    price = newPrice;
}

Book& Book::operator+=(double addPrice){
    this->price += addPrice;
    return *this;
}