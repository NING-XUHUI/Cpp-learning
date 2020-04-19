/**
* @file Book.h
* @brief 
* @details
* @date 2020/4/19 11:58 下午
* Created by 宁旭晖 on 2020/4/19.
*/
#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include "Date.h"
#include "TP.h"
#include <iostream>
#include <utility>
using namespace std;
class Book {
private:
    int id;
    string title;
    string author;
    Date date;
    int num;
    ui renewnum;
    string startdate;
    string enddate;

public:
    Book() : id(0), title("NULL"), author("NULL"), date(), num(3), renewnum(0) {}
    Book(int i, string t, string au, Date d)
        : id(i), title(std::move(t)), author(std::move(au)), date(d), num(3), renewnum(0) {}
    int getID() const {
        return id;
    }
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author;
    }
    Date getDate() const {
        return date;
    }
    int getNum() const {
        return num;
    }
    ui getRenewnum() const {
        return renewnum;
    }

    void setId(int id) {
        this->id = id;
    }
    void setTitle(const string &title) {
        this->title = title;
    }
    void setAuthor(const string &author) {
        this->author = author;
    }
    void setDate(const Date &date) {
        this->date = date;
    }
    void setNum(int num) {
        this->num = num;
    }
    void setRenewnum(ui re) {
        this->renewnum = re;
    }
    string getTime() const;
    void dispdate() const;

    friend ostream &operator<<(ostream &os, const Book &book);
    friend istream &operator>>(istream &is, Book &book);
};


#endif//LIBRARY_BOOK_H
