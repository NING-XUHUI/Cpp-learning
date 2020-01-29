/*
例3-6 投骰子的随机游戏
每个骰子有六面，点数分别为1、2、3、4、5、6。游戏者在程序开始时输入一个无符号整数，作为产生随机数的种子。

每轮投两次骰子，第一轮如果和数为7或11则为胜，游戏结束；和数为2、3或12则为负，游戏结束；和数为其它值则将此值作为自己的点数，继续第二轮、第三轮...直到某轮的和数等于点数则取胜，若在此前出现和数为7则为负。

 
rand函数
l  函数原型：int rand(void)；
l  所需头文件：<cstdlib>

l  功能和返回值：求出并返回一个伪随机数

 

srand函数
l  void srand(unsigned int seed);
l  参数：seed产生随机数的种子
l  所需头文件：<cstdlib>
l  功能：为使rand()产生一序列伪随机整数而设置起始点。使用1作为seed参数，可以重新初化rand()。
*/

#include<iostream>
#include<cstdlib>

using namespace std;

enum GameStatus {WIN,LOSE,PLAYING};

int rollDice();


int main(){
    
    int sum,myPoint;
    GameStatus status;
    unsigned seed;    
    cout<<"please enter an unsifned integer"<<endl;
    
    cin>>seed;
    srand(seed);
    sum = rollDice();
    
    switch(sum){
        case 7:
        case 11:
            status = WIN;
            break;
        case 2:
        case 3:
        case 12:
            status = LOSE;
            break;
        default:
            status = PLAYING;
            myPoint = sum;
            cout<<"point is "<<sum<<endl;
            break;
    }
    
    while(status == PLAYING){
        sum = rollDice();
        if(sum == myPoint)
            status = WIN;
        else if(sum == 7)
            status = LOSE;
    }
    
    if(status == WIN)
        cout<<"player wins"<<endl;
    else
        cout<<"player loses"<<endl;
    
    return 0;
}

int rollDice(){
    int die1 = 1 + rand()%6;
    int die2 = 1 + rand()%6;
    int sum = die1 + die2;
    cout<<"player rolled"<<die1<<"+"<<die2<<"="<<sum<<endl;
    return sum;
}




