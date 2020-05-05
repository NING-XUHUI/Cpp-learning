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
/*!
 * @brief
 *
 */
void ManagerView::select_memu() {
    int number;
    cout << "请输入选项：";
    cin >> number;
    if (number == 1) {
        this->input_student();
    } else if (number == 2) {
        this->output_student();
    } else if (number == 3) {
        // this->delete_student();
    } else if (number == 4) {
    } else if (number == 5) {
        this->output_students_by_score();
    }
}

void ManagerView::input_student() {
    string name;
    ui age;
    ui score;
    cout << "请输入学生姓名:" << endl;
    cin >> name;
    cout << "请输入学生年龄:" << endl;
    cin >> age;
    cout << "请输入学生成绩:" << endl;
    cin >> score;
    manager.add_student(StudentModel(name, age, score));

}

void ManagerView::output_student(std::list<StudentModel>) {
    for (const auto& stu : manager.getAllStds()) {
        cout << stu << endl;
    }
}

void ManagerView::main() {
    while (true){
        display_menu();
        select_memu();
    }
}

void ManagerView::output_students_by_score() {


}
