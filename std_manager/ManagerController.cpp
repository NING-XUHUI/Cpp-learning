//
// Created by 宁旭晖 on 2020/4/3.
//

#include "ManagerController.h"

std::list<StudentModel> ManagerController::order_by_score()
{
    std::list<StudentModel> new_list = this->all_stds;
    new_list.sort();
    return new_list;
}

void ManagerController::add_student(StudentModel stu)
{
    stu.setId(this->generate_id());
    all_stds.push_back(stu);
}
