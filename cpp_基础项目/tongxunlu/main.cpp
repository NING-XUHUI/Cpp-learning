#include <iostream>
#include <string>

using namespace std;
#define MAX 1000

struct Person {
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Add;
};

struct AddressBooks {
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(AddressBooks *abs) {
    if (abs->m_Size == MAX) {
        cout << "通讯录已满" << endl;
        return;
    } else {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "请输入性别" << endl;
        cout << "1.男" << endl;
        cout << "2.女" << endl;
        int sex = 0;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误" << endl;
        }

        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "请输入电话" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout << "请输入地址" << endl;
        string add;
        cin >> add;
        abs->personArray[abs->m_Size].m_Add = add;

        abs->m_Size++;
    }
}

void showPerson(AddressBooks *abs) {
    if (abs->m_Size == 0) {
        cout << "空" << endl;
        return;
    }
    for (int i = 0; i < abs->m_Size; i++) {
        cout << "*******************" << endl;
        cout << "姓名: " << abs->personArray[i].m_Name << endl;
        cout << "性别: " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << endl;
        cout << "年龄: " << abs->personArray[i].m_Age << endl;
        cout << "电话: " << abs->personArray[i].m_Phone << endl;
        cout << "住址: " << abs->personArray[i].m_Add << endl;
    }
}

void showMenu() {
    cout << "*************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****  0.退出通讯录  *****" << endl;
    cout << "*************************" << endl;
}

int main() {

    AddressBooks abs;
    abs.m_Size = 0;


    int select = 0;

    while (true) {
        showMenu();
        cin >> select;
        switch (select) {
            case 1:
                addPerson(&abs);
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                return 0;
            default:
                break;
        }
    }

    return 0;
}
