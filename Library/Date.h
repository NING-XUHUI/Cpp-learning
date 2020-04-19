/**
* @file Date.h
* @brief 
* @details
* @date 2020/4/19 11:58 下午
* Created by 宁旭晖 on 2020/4/19.
*/
#ifndef LIBRARY_DATE_H
#define LIBRARY_DATE_H
#include "TP.h"
#include <iostream>

using namespace std;
class Date {
private:
    ui year;
    ui month;

public:
    Date() : year(0), month(0) {}
    Date(ui y, ui m) : year(y), month(m) {}
    ui getYear() const {
        return year;
    }
    ui getMonth() const {
        return month;
    }
    void setYear(const ui &y) {
        year = y;
    }
    void setMonth(const ui &m) {
        month = m;
    }

    void display() const;
    friend istream &operator>>(istream &, Date &);
    friend ostream &operator<<(ostream &,const Date &);
};


#endif//LIBRARY_DATE_H
