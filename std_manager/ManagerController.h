//
// Created by 宁旭晖 on 2020/4/3.
//

#ifndef STD_MANAGER_MANAGERCONTROLLER_H
#define STD_MANAGER_MANAGERCONTROLLER_H

#include "StudentModel.h"
#include <list>

typedef unsigned int ui;

class ManagerController {
private:
    std::list<StudentModel> all_stds;
public:
    ManagerController() {
        all_stds = {};
    }

    const std::list<StudentModel> &getAllStds() const {
        return all_stds;
    }

    ui generate_id() {
        ui new_id;
        if (all_stds.size() > 1) {
            new_id = all_stds.back().getId() + 1;
        } else {
            new_id = 1;
        }
        return new_id;
    }

    void remove_student(ui id) {

    }

};


#endif //STD_MANAGER_MANAGERCONTROLLER_H
