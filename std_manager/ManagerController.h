//
// Created by 宁旭晖 on 2020/4/3.
//

#ifndef STD_MANAGER_MANAGERCONTROLLER_H
#define STD_MANAGER_MANAGERCONTROLLER_H

#include <list>
#include "StudentModel.h"

typedef unsigned int ui;

class ManagerController
{
  private:
    std::list<StudentModel> all_stds;
  public:
    ManagerController() { all_stds = {}; }

    const std::list<StudentModel> &getAllStds() const { return all_stds; }

    /**
     * 添加学生
     * @param stu
     */
    void add_student(StudentModel stu);

    /**
     * 自动生成id
     * @return
     */
    ui generate_id()
    {
        ui new_id;
        if (!all_stds.empty())
        {
            new_id = all_stds.back().getId() + 1;
        }
        else
        {
            new_id = 1;
        }
        return new_id;
    }

    /*void remove_student(ui id){
        for (const auto& stu : all_stds){
            if (stu.getId() == id){
                all_stds.remove(stu);
            }
        }
    }*/

    std::list<StudentModel> order_by_score();
};

#endif  // STD_MANAGER_MANAGERCONTROLLER_H
