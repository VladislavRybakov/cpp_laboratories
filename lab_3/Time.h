#pragma once
#include <iostream>

class Time
{     //Time class
public:
  Time() = default; // конструктор по умолчанию
  Time(int, int); // конструктор со значениями минут и секунд
  void setTime(int, int); // сеттер
  void getTime(int&, int&) const; // геттер
  friend std::ostream& operator << (std::ostream& out, const Time& a);
  friend std::istream& operator >> (std::istream& in, Time& a);
  friend bool operator==(const Time& a, const int& i);
  Time& operator=(const Time& a);
  Time& operator=(const int& a);

private:
  int min, sec; // минуты и секунды соответственно
};

Time::Time(int mi, int se) {
  min = (mi + se / 60) % 60; // проверка если секунд ввелось больше 60 и минут получается больше 60, то высчитывается правильное время
  sec = se % 60; // высчитывается правильное кол-во секунд
}

void Time::setTime(int mi, int se) {
  min = (mi + se / 60) % 60;
  sec = se % 60;
}

void Time::getTime(int& one, int& two) const { // в две ссылки кладутся значения полей объекта
  one = min;
  two = sec;
}

std::ostream& operator << (std::ostream& out, const Time& a) { // оператор вывода
  if (a.sec > 9) { // если число секунд двузначно
    out << a.min << ":" << a.sec;
  }
  else {
    out << a.min << ":" << "0" << a.sec; // если число секунд однозначно, то добавляем после двоеточия 0
  }
  return out;
}

std::istream& operator >> (std::istream& in, Time& a) { // оператор ввода
  char o; // в переменную о должнен ввестись символ ':'
  int mi, se;
  in >> mi >> o >> se; // подразумевается, что ввод будет в виде mm:ss
  a.setTime(mi, se);
  return in;
}

Time& Time::operator=(const Time& a) { // оператор присваивания такого же типа
  min = a.min;
  sec = a.sec;
  return *this;
}

Time& Time::operator=(const int& a) { // оператор присваивания переменной типа Time значения int (для работы с NULL)
  min = (a / 60) % 60;
  sec = a % 60;
  return *this;
}

bool operator==(const Time& a, const int& i) { // оператор сравнения переменной типа Time и типа int (для сравнения с NULL)
  if (a.min == (i / 60) % 60 && a.sec == i % 60) return true;
  return false;
}