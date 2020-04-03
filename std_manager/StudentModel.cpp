//
// Created by 宁旭晖 on 2020/4/3.
//

#include "StudentModel.h"

#include <utility>

void StudentModel::setId(ui _id) {
    this->id = _id;
}

void StudentModel::setName(std::string _name) {
    this->name = std::move(_name);
}

void StudentModel::setAge(ui _age) {
    this->age = _age;
}

void StudentModel::setScore(ui _score) {
    this->score = _score;
}



