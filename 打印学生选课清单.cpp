/*
假设全校有最多40000名学生和最多2500门课程。现给出每门课的选课学生名单，要求输出每个前来查询的学生的选课清单。

输入的第一行是两个正整数：N（≤40000），为前来查询课表的学生总数；K（≤2500），为总课程数。此后顺序给出课程1到K的选课学生名单。格式为：对每一门课，首先在一行中输出课程编号（简单起见，课程从1到K编号）和选课学生总数（之间用空格分隔），之后在第二行给出学生名单，相邻两个学生名字用1个空格分隔。学生姓名由3个大写英文字母+1位数字组成。选课信息之后，在一行内给出了N个前来查询课表的学生的名字，相邻两个学生名字用1个空格分隔。

对每位前来查询课表的学生，首先输出其名字，随后在同一行中输出一个正整数C，代表该生所选的课程门数，随后按递增顺序输出C个课程的编号。相邻数据用1个空格分隔，注意行末不能输出多余空格。

10 5
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6

ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5

*/


#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <istream>
#include <algorithm>
#include <time.h>
using namespace std;

//clock_t tstart, tend;

int mhash(char * name) {
    return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + name[3] - '0';
}
int main(){
    vector<int> s_c[26 * 26 * 26 * 10 + 1];
    int stuCount;
    int courseCount;
    char name[5];
    cin >> stuCount >> courseCount;
    //tstart = clock();
    if(stuCount != 0 && courseCount != 0){
        for(int i = 0;i < courseCount;i++){
            int cname;
            int scount;
            cin >> cname >> scount;
            if(scount <= 0){
                continue;
            }
            for (int j=0; j<scount; j++) {
                cin >> name;
                int hash = mhash(name);
                s_c[hash].push_back(cname);
            }
        }
        for (int i =0; i < stuCount; i++) {
            cin >> name;
            int hash = mhash(name);
            sort(s_c[hash].begin(),s_c[hash].end());
            cout << name << " " << s_c[hash].size();
            for (unsigned int j = 0; j < s_c[hash].size(); j++) {
                cout << " " << s_c[hash][j];
            }
            cout << endl;
        }
    }
    //tend = clock();
    //cout<<(double)(tend-tstart)/CLOCKS_PER_SEC<<endl;
    return 0;
}


