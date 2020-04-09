/**
 * @file viewController.cpp
 * @brief
 * @details
 * @date 2020/4/6 11:26 上午
 * Created by 宁旭晖 on 2020/4/6.
 */
#include "../head/viewController.h"
#include <iostream>
using namespace std;

void ViewController::showMenu()
{
    cout << "**********************" << endl;
    cout << "(1.自选球队对战" << endl;
    cout << "(2.自组球队对战" << endl;
    cout << "(3.查看球员数据" << endl;
    cout << "**********************" << endl;
}
void ViewController::main()
{
    showMenu();


}
