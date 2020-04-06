/**
 * @file Player.h
 * @brief
 * @details
 * @date 2020/4/6 11:22 上午
 * Created by 宁旭晖 on 2020/4/6.
 */

#ifndef NBA_PLAYER_H
#define NBA_PLAYER_H

#include <ostream>
#include <string>

/**
 * @brief
 */
class Player
{
  private:
    // todo 完善球员数据 python接口
    std::string name;
    int age;
    int value;
    double twoRates;
    double threeRates;
    double freeRates;

  public:
    Player(std::string name,
           int age,
           int value,
           double twoRates,
           double threeRates,
           double freeRates);

    const std::string &getName() const { return name; }
    int getAge() const { return age; }
    int getValue() const { return value; }
    double getTwoRates() const { return twoRates; }
    double getThreeRates() const { return threeRates; }
    double getFreeRates() const { return freeRates; }

    void setName(const std::string &_name) { Player::name = _name; }
    void setAge(int _age) { Player::age = _age; }
    void setValue(int _value) { Player::value = _value; }
    void setTwoRates(double _twoRates) { Player::twoRates = _twoRates; }
    void setThreeRates(double _threeRates) { Player::threeRates = _threeRates; }
    void setFreeRates(double _freeRates) { Player::freeRates = _freeRates; }

    bool operator==(const Player &rhs) const;
    bool operator!=(const Player &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
};

#endif  // NBA_PLAYER_H
