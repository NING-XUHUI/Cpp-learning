//
//  main.cpp
//  练习
//
//  Created by 宁旭晖 on 2019/5/25.
//  Copyright © 2019 宁旭晖. All rights reserved.
//
#include <cstdio>
#include <iostream>

using namespace std;
const int Max = 30;

class Student;

void setdata(Student &s);
void count(Student &s);
void sort(Student S[], int N);
double getAverage(Student S[], int N);
void print(Student &s);
int search(Student S[], int N, char *n);
class Student {
public:
  char number[Max];
  char name[Max];
  double chinese;
  double math;
  double english;
  double total;
  double average;
  int rank;
};

void setdata(Student &s) {
  std::cout << "请输入学号姓名语文数学英语成绩：";
  std::cin >> s.number >> s.name >> s.chinese >> s.math >> s.english;
  s.total = 0;
  s.average = 0;
  s.rank = 0;
}

void count(Student &s) {
  s.total = s.chinese + s.math + s.english;
  s.average = s.total / 3;
}
void sort(Student S[], int N) {
  int index;
  Student inserter;
  for (int i = 1; i < N; i++) {
    inserter = S[i];
    index = i - 1;
    while (index >= 0 && inserter.average > S[index].average) {
      S[index + 1] = S[index];
      index--;
    }
    S[index + 1] = inserter;
  }
  for (int j = 0; j < N; j++)
    S[j].rank = j + 1;
}

double getAverage(Student S[], int N) {
  double Average = 0;
  for (int i = 0; i < N; i++)
    Average += (S[i].chinese + S[i].math + S[i].english);

  Average /= (N * 3);
  return Average;
}
void print(Student &s) {
  std::cout << "排名"
            << "\t"
            << "学号"
            << "\t"
            << "姓名"
            << "\t"
            << "语文"
            << "\t"
            << "数学"
            << "\t"
            << "英语"
            << "\t"
            << "总分"
            << "\t"
            << "平均分" << std::endl;
  std::cout << s.rank << "\t" << s.number << "\t" << s.name << "\t" << s.chinese
            << "\t" << s.math << "\t" << s.english << "\t" << s.total << "\t"
            << s.average << std::endl;
}
int search(Student S[], int N, char *n) {
  for (int i = 0; i < N; i++) {
    if (strcmp(S[i].number, n) == 0)
      return i;
  }
  return -1;
}
int main() {
  const int M = 5;
  Student S[M];
  for (int i = 0; i < M; i++) {
    std::cout << "下面输入第" << i + 1 << "位同学的成绩:" << std::endl;
    setdata(S[i]);
    count(S[i]);
    std::cout << std::endl;
  }
  sort(S, M);
  int order = 1;
  while (order != 4) {
    std::cout << "***************************命令菜单**********************"
              << std::endl;
    std::cout << "1.打印所有排名" << std::endl;
    std::cout << "2.打印出成绩在全班平均分以上的学生名单和数据信息"
              << std::endl;
    std::cout << "3.任意输入一个学号，查找出该学生在班级中的排名及其成绩"
              << std::endl;
    std::cout << "4.推出系统" << std::endl;
    std::cout << "********************************************************"
              << std::endl;
    std::cout << "输入命令选择:";
    std::cin >> order;
    switch (order) {
    case 1: {
      for (int j = 0; j < M; j++)
        print(S[j]);
    } break;
    case 2: {
      double compare = getAverage(S, M);

      for (int k = 0; k < M; k++) {
        if (S[k].average > compare)
          print(S[k]);
      }
    } break;
    case 3: {
      char code[Max];
      std::cout << "请输入要查找的学号:";
      std::cin >> code;
      int result = search(S, M, code);
      if (result == -1)
        std::cout << "学号不存在" << std::endl;
      else
        print(S[result]);

    } break;
    case 4:
      break;
    default:
      std::cout << "输入命令不存在" << std::endl;
    }
  }
  return 0;
}
