/**
* @file Book.cpp
* @brief 
* @details
* @date 2020/4/19 11:58 下午
* Created by 宁旭晖 on 2020/4/19.
*/
#include "Book.h"
#include <iomanip>
string Book::getTime() const {
    time_t t = time(nullptr);
    char tmp[11];
    strftime(tmp, sizeof(tmp), "%Y %m %d", localtime(&t));
    return tmp;
}
void Book::dispdate() const {
    string str = getTime();
    int x = (str[6] - 48) + 2;
    for (int i = 0; i <= 4; i++) {
        cout << str[i];
    }
    cout << str[5] << x;
    for (int i = 7; i <= 9; i++) {
        cout << str[i];
    }
}
ostream &operator<<(ostream &os, const Book &book) {
    os << book.id << " " << book.title << " " << book.author << " " << book.date << " " << book.num << " " << book.renewnum;
    return os;
}
istream &operator>>(istream &is, Book &book) {
    is >> book.id >> book.title >> book.author >> book.date >> book.num >> book.renewnum;
    return is;
}
