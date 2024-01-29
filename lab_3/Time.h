#pragma once
#include <iostream>

class Time
{     //Time class
public:
  Time() = default; // ����������� �� ���������
  Time(int, int); // ����������� �� ���������� ����� � ������
  void setTime(int, int); // ������
  void getTime(int&, int&) const; // ������
  friend std::ostream& operator << (std::ostream& out, const Time& a);
  friend std::istream& operator >> (std::istream& in, Time& a);
  friend bool operator==(const Time& a, const int& i);
  Time& operator=(const Time& a);
  Time& operator=(const int& a);

private:
  int min, sec; // ������ � ������� ��������������
};

Time::Time(int mi, int se) {
  min = (mi + se / 60) % 60; // �������� ���� ������ ������� ������ 60 � ����� ���������� ������ 60, �� ������������� ���������� �����
  sec = se % 60; // ������������� ���������� ���-�� ������
}

void Time::setTime(int mi, int se) {
  min = (mi + se / 60) % 60;
  sec = se % 60;
}

void Time::getTime(int& one, int& two) const { // � ��� ������ �������� �������� ����� �������
  one = min;
  two = sec;
}

std::ostream& operator << (std::ostream& out, const Time& a) { // �������� ������
  if (a.sec > 9) { // ���� ����� ������ ���������
    out << a.min << ":" << a.sec;
  }
  else {
    out << a.min << ":" << "0" << a.sec; // ���� ����� ������ ����������, �� ��������� ����� ��������� 0
  }
  return out;
}

std::istream& operator >> (std::istream& in, Time& a) { // �������� �����
  char o; // � ���������� � ������� �������� ������ ':'
  int mi, se;
  in >> mi >> o >> se; // ���������������, ��� ���� ����� � ���� mm:ss
  a.setTime(mi, se);
  return in;
}

Time& Time::operator=(const Time& a) { // �������� ������������ ������ �� ����
  min = a.min;
  sec = a.sec;
  return *this;
}

Time& Time::operator=(const int& a) { // �������� ������������ ���������� ���� Time �������� int (��� ������ � NULL)
  min = (a / 60) % 60;
  sec = a % 60;
  return *this;
}

bool operator==(const Time& a, const int& i) { // �������� ��������� ���������� ���� Time � ���� int (��� ��������� � NULL)
  if (a.min == (i / 60) % 60 && a.sec == i % 60) return true;
  return false;
}