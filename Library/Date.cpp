/**
* @file Date.cpp
* @brief 
* @details
* @date 2020/4/19 11:58 下午
* Created by 宁旭晖 on 2020/4/19.
*/
#include "Date.h"
void Date::display() const {
    cout << year << "年" << month << "月" << endl;
}
istream &operator>>(istream &in, Date &date) {
    in >> date.year >> date.month;
    return in;
}
ostream &operator<<(ostream &ou,const Date &date) {
    ou << date.year << " " << date.month;
    return ou;
}
