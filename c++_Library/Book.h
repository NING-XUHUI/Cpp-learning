//
// Created by 宁旭晖 on 2020/3/24.
//

#ifndef C___LIBRARY_BOOK_H
#define C___LIBRARY_BOOK_H

#include <stdio.h>
#include <string>
class Book{
public:
    Book() = default;
    explicit Book(const std::string n = " ",const double p = 0.0,const std::string w = " ")
            :name(n),price(p),writer(w){ }
    double getPrice()const;
    std::string getName()const;
    std::string getWriter()const;
    void setPrice(double &newPrice);
    Book& operator +=(double addPrice);
private:
    std::string name;
    double price;
    std::string writer;
};
#endif //C___LIBRARY_BOOK_H
