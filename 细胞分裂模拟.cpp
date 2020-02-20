//模拟一种细胞在诞生（即上次分裂）后会在500-2000秒内分裂为两个细胞，每个细胞又按照同样的规律继续分裂。
#include<queue>
#include<iostream>
#include<stdlib.h>
using namespace std;
const int SPLIT_TIME_MIN = 500;//细胞分裂最短时间
const int SPLIT_TIME_MAX = 2000;//最长

class Cell;
priority_queue<Cell> cellQueue;

class Cell{
private:
  static int count;//细胞总数
  int id;//细胞编号
  int time;//细胞分裂时间
public:
  Cell(int birth):id(count++){
    //birth为细胞诞生时间
    //初始化，确定细胞分裂时间
    time = birth + (rand()%(SPLIT_TIME_MAX - SPLIT_TIME_MIN))+SPLIT_TIME_MIN;
  }
  int getId()const{return id;}//得到细胞编号
  int getSplitTime()const{return time;}
  bool operator < (const Cell &s)const{return time > s.time;}//定义<
  void split()const{//分裂
    Cell child1(time),child2(time);//建立两个子细胞
    cout<<time<<"s:Cell#"<<id<<"split to"<<child1.getId()<<"and"<<child2.getId()<<endl;
    cellQueue.push(child1);
    cellQueue.push(child2);
  }
};

int Cell::count = 0;


int main(){
  srand(static_cast<unsigned>(time(0)));
  int t;//模拟时间长度
  cout<<"Simulation time:";
  cin>>t;
  cellQueue.push(Cell(0));//将第一个细胞压入队列
  while(cellQueue.top().getSplitTime() <= t){
    cellQueue.top().split();//模拟下一个细胞的分裂
    cellQueue.pop();//将刚刚分裂的细胞弹出g
  }
  return 0;
} 
