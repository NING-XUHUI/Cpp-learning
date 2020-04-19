/**
* @file User.h
* @brief 
* @details
* @date 2020/4/19 11:30 下午
* Created by 宁旭晖 on 2020/4/19.
*/
#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H

#include "TP.h"
#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include ""
using namespace std;
class User {
private:
    string name;
    ll id;
    string passWard;
    int bookNum;

public:
    vector<>

    User() : name("NULL"), id(0), passWard("123456"), bookNum(0) {}
    User(string n, ll i, string pw) : name(std::move(n)), id(i), passWard(std::move(pw)), bookNum(0) {}
    string getName() const {
        return name;
    }
    ll getID() const {
        return id;
    }
    string getPassward() const {
        return passWard;
    }
    int getBookNumber() const {
        return bookNum;
    }

    void setName(string n) {
        name = std::move(n);
    }
    void setID(const ll &i) {
        id = i;
    }
    void setPassWard(string pw) {
        passWard = std::move(pw);
    }
    void setBookNum(int n) {
        bookNum = n;
    }

    bool isPassWard(const string &p);
    friend istream &operator>>(istream &, User &);
    friend ostream &operator<<(ostream &, User &);

    void display() const;
};


#endif//LIBRARY_USER_H
