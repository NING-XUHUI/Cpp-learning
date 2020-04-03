//
// Created by 宁旭晖 on 2020/4/3.
//

#include "ManagerView.h"
#include <iostream>
#include "StudentModel.h"

typedef unsigned int ui;
using namespace std;

void ManagerView::display_menu() {
    /* 显示菜单 */
    cout << "1) 添加学生" << endl;
    cout << "2) 显示学生" << endl;
    cout << "3) 删除学生" << endl;
    cout << "4) 修改学生" << endl;
    cout << "5) 按成绩升序排列" << endl;
}

void ManagerView::select_memu() {
    int number;
    cout << "请输入选项：";
    cin >> number;
    if (number == 1) {
        this->input_student();
    } else if (number == 2) {
        this->output_student();
    } else if (number == 3) {
        this->delete_student();
    } else if (number == 4) {
    } else if (number == 5) {
        this->output_students_by_score();
    }
}

void ManagerView::input_student() {
    string name;

}
