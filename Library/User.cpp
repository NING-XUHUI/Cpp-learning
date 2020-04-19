/**
* @file User.cpp
* @brief 
* @details
* @date 2020/4/19 11:30 下午
* Created by 宁旭晖 on 2020/4/19.
*/
#include "User.h"
bool User::isPassWard(const string &p) {
    if (passWard == p)
        return true;
    else
        return false;
}
istream &operator>>(istream &in, User &user) {
    in >> user.name >> user.id >> user.passWard;
    return in;
}
ostream &operator<<(ostream &ou, User &user) {
    ou << user.id << " " << user.name << " " << user.passWard;
    return ou;
}
void User::display() const {

}
