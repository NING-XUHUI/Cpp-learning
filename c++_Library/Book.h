//
// Created by 宁旭晖 on 2020/3/24.
//

#ifndef C___LIBRARY_BOOK_H
#define C___LIBRARY_BOOK_H

#include <iostream>
#include <string>
#include <utility>
class Book {
public:
  explicit Book(std::string n = " ", double p = 0.0,
                std::string w = " ")
      :name(std::move(n)), price(p),writer(std::move(w)) {}
  double getPrice() const;
  std::string getName() const;
  std::string getWriter() const;
  void setPrice(double &newPrice);
  Book &operator+=(double addPrice);
  friend std::ostream &operator<<(std::ostream &os, const Book &book);

private:
  std::string name;
  double price;
  std::string writer;
};
#endif // C___LIBRARY_BOOK_H
