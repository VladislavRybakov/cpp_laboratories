#pragma once
#include <iostream>

template <typename abstracted>
class Node
{
public:
  Node* next;
  abstracted data;
  Node() : next(NULL) {}
  explicit Node(const abstracted& smth) : data(smth), next(NULL) {}

  friend std::ostream& operator << (std::ostream& out,const Node& a) { 
    out << a.data << " "; // у типа abstracted должен быть перегружен оператор вывода
    return out;
  }

  friend std::istream& operator >> (std::istream& in, Node& a) { // оператор ввода
    abstracted smt;
    in >> smt; // у типа abstracted должен быть перегружен оператор ввода
    a.data = smt;
    return in;
  }

  Node& operator=(const Node& a) { // оператор присваивания
    data = a.data;
    next = a.next;
    return *this;
  }
};