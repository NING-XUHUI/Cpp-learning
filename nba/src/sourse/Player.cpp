/**
 * @file Player.cpp
 * @brief
 * @details
 * @date 2020/4/6 11:22 上午
 * Created by 宁旭晖 on 2020/4/6.
 */
#include "../head/Player.h"

#include <utility>

Player::Player(std::string name,
               int age,
               int value,
               double twoRates,
               double threeRates,
               double freeRates)
    : name(std::move(name)),
      age(age),
      value(value),
      twoRates(twoRates),
      threeRates(threeRates),
      freeRates(freeRates)
{}
bool Player::operator==(const Player &rhs) const
{
    return name == rhs.name && age == rhs.age && value == rhs.value && twoRates == rhs.twoRates &&
           threeRates == rhs.threeRates && freeRates == rhs.freeRates;
}
bool Player::operator!=(const Player &rhs) const
{
    return !(rhs == *this);
}
std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << "name: " << player.name << " age: " << player.age << " value: " << player.value
       << " twoRates: " << player.twoRates << " threeRates: " << player.threeRates
       << " freeRates: " << player.freeRates;
    return os;
}
