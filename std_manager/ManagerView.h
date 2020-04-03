//
// Created by 宁旭晖 on 2020/4/3.
//

#ifndef STD_MANAGER_MANAGERVIEW_H
#define STD_MANAGER_MANAGERVIEW_H

#include "ManagerController.h"

class ManagerView{
private:
    ManagerController manager;
public:
    void input_student();

    void output_student();

    void output_students_by_score();

    // void delete_student();

    void display_menu();

    void select_memu();

    void main();

};

#endif //STD_MANAGER_MANAGERVIEW_H
