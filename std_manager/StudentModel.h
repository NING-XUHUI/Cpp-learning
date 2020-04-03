//
// Created by 宁旭晖 on 2020/4/3.
//


#ifndef STD_MANAGER_STUDENTMODEL_H
#define STD_MANAGER_STUDENTMODEL_H

#include <string>
#include <utility>

typedef unsigned int ui;

class StudentModel {
private:
    ui id;
    std::string name;
    ui age;
    ui score;
public:
    StudentModel(ui _id, std::string _name, ui _age, ui _score) :
            id(_id), name(std::move(_name)), age(_age), score(_score) {}

    StudentModel(const StudentModel &stu) {
        id = stu.getId();
        name = stu.getName();
        age = stu.getAge();
        score = stu.getAge();
    }

    ui getId() const { return id; }

    std::string getName() const { return name; }

    ui getAge() const { return age; }

    ui getScore() const { return score; }

    void setId(ui _id);

    void setName(std::string name);

    void setAge(ui _age);

    void setScore(ui _score);

};


#endif //STD_MANAGER_STUDENTMODEL_H
