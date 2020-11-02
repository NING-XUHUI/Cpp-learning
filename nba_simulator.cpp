#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

#define CLE "骑士队"
#define GD "勇士队"

static int team1_score = 0; //统计队伍1的分数
static int team2_score = 0; //统计队伍2的分数

/*
int RandNo1(){
  srand(time(0));
  return rand()%100;
}
*/
//延时函数
void delay_ms(unsigned long ms) {
  clock_t start = clock();
  while (clock() - start < ms)
    ;
}

class Player {
public:
  int tag;                          //球员标签，用于区分队伍
  string player_name;               //球员姓名
  int choose, three_rate, two_rate; //球员出手选择，三分命中率、两分命中率
  int total_made;                   //总命中数
  int three_made;                   //三分命中数
  int totoal_shoot;                 //总出手数
  Player(string name, int cho, int thr_rate, int tw_rate, int t)
      : player_name(name), tag(t), choose(cho), three_rate(thr_rate),
        two_rate(tw_rate) {
    total_made = 0;
    three_made = 0;
    totoal_shoot = 0;
  }

  void shoot();            //投篮
  void dunk();             //灌篮
  void updateScore(int s); //更新球队分数
  void printInformation(); //打印球员数据信息
};

void Player::printInformation() {
  cout << player_name << ":  得分"
       << (three_made * 3 + (total_made - three_made) * 2) << "出手"
       << total_made << "/" << totoal_shoot << " " << endl;
}
void Player::updateScore(int s) { //根据标签更新对应球队分数
  if (tag == 1) {
    team1_score += s;
  } else
    team2_score += s;
}

void Player::shoot() {
  int a = rand() % 100; //出手选择随机数
  int b = rand() % 100; //命中率随机数
  this->totoal_shoot++;
  if (a >= 0 && a <= this->choose) {
    cout << this->player_name << "三分出手" << endl;
    if (b >= 0 && b <= three_rate) {
      cout << "我的三分箭，是地狱的火焰!!" << endl;

      cout << "三分命中！" << endl;
      this->three_made++;
      this->total_made++;
      this->updateScore(3);
    } else {
      cout << "框都给你干歪咯" << endl;
    }
  } else {
    cout << this->player_name << "中距离出手" << endl;
    if (b >= 0 && b <= two_rate) {
      cout << "两分到手!" << endl;
      this->total_made++;
      this->updateScore(2);
    } else {
      cout << "框都给你干歪咯" << endl;
    }
  }
}

void Player::dunk() {
  this->totoal_shoot++;
  int b = rand() % 100;
  if (b >= 0 && b <= two_rate) {
    cout << this->player_name << "力劈华山的一记暴扣!!" << endl;
    this->total_made++;
    this->updateScore(2);
  } else {
    cout << this->player_name << "惨遭框血帽！" << endl;
  }
}

int main() {
  srand((unsigned int)time(0) * 10);

  Player James("詹姆斯", 10, 51, 37, 1);
  Player Love("勒夫", 38, 33, 33, 1);
  Player TT("汤普森", 0, 0, 54, 1);
  Player Irving("欧文", 22, 41, 51, 1);
  Player JR("JR史密斯", 65, 38, 39, 1);
  Player Curry("库里", 51, 40, 47, 2);
  Player Thompson("汤普森", 49, 37, 46, 2);
  Player Durant("杜兰特", 24, 45, 52, 2);
  Player Green("格林", 35, 31, 47, 2);
  Player Looney("鲁尼", 0, 0, 59, 2);
  
  cout << "比赛开始" << endl;
  int sum_time = 2880;
  cout << endl;
  while (sum_time > 0) {

    int x = rand() % 100;
    if (x >= 0 && x <= 29)
      Curry.shoot();
    else if (x > 29 && x <= 59)
      Durant.shoot();
    else if (x > 59 && x <= 80)
      Thompson.shoot();
    else if (x > 80 && x <= 85)
      Looney.dunk();
    else
      Green.shoot();
    cout << endl;
    cout << "现在比分  " << CLE << team1_score << " : " << GD << team2_score
         << endl;
    cout << endl;
    delay_ms(10000);
    int y = rand() % 100;

    if (y >= 0 && y <= 34)
      James.shoot();
    else if (y > 34 && y <= 65)
      Irving.shoot();
    else if (y > 65 && y <= 77)
      JR.shoot();
    else if (y > 77 && y <= 91)
      Love.shoot();
    else
      TT.dunk();
    delay_ms(10000);
    cout << endl;
    sum_time -= 36;
    cout << "现在比分  " << CLE << team1_score << " : " << GD << team2_score
         << endl;
    cout << endl;
  }
  cout << "比赛结束" << endl;

  Player players[10] = {James, Love,     Irving, TT,    JR,
                        Curry, Thompson, Looney, Green, Durant};

  cout << "球员数据" << endl;

  for (auto a : players) {
    a.printInformation();
  }
      return 0;
}
