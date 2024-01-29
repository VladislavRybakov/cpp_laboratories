#include "citizen.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


Citizen::Citizen(const string surname, const string name, const string father, const string street, const int house, const int apart, const int year) { // ���������� ������������ �� ����� �����������
  this->surname = surname; // ����������� ����� ������� ��������������� ���������� ��������
  this->name = name;
  this->father = father;
  this->street = street;
  this->house = house;
  this->apart = apart;
  this->year = year;
}
void Citizen::set(const string surname, const string name, const string father, const string street, const int house, const int apart, const int year) { // ���������� �������
  this->surname = surname; // ����������� ����� ������� ��������������� ���������� ��������
  this->name = name;
  this->father = father;
  this->street = street;
  this->house = house;
  this->apart = apart;
  this->year = year;
}
Citizen::Citizen(const Citizen& a) { // ���������� ������������ �����������
  this->surname = a.get_surname(); // ����� ���������� ������� ����������� �������� ����� ����������� �� ���� ������� � ������� ��������
  this->name = a.get_name();
  this->father = a.get_father();
  this->street = a.get_street();
  this->house = a.get_house();
  this->apart = a.get_apart();
  this->year = a.get_year();
}
Citizen& Citizen::operator=(const Citizen& a) { // ���������� ���������� ��������� ������������
  this->surname = a.get_surname(); // ����� ���������� ������� ����������� �������� ����� ����������� �� ���� ������� � ������� ��������
  this->name = a.get_name();
  this->father = a.get_father();
  this->street = a.get_street();
  this->house = a.get_house();
  this->apart = a.get_apart();
  this->year = a.get_year();
  return *this; //���������� ������ �� ������� ������
}
bool operator>(const Citizen& a, const Citizen& b) { // ���������� ���������� ��������� > (�� ������� ���������� ��������� ����� �� �������� ������������ ������)
  if (a.get_street() > b.get_street()) { // ���������� ����� ���� �������� � ������������������ �������
    return true; // ���� ����� ������, �� ���������� true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() > b.get_house())) { // ���� ����� ����������, ���������� ����� �����
    return true; // ���� ����� ������, �� ���������� true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() > b.get_apart())) { // ���� ������ ����� ������ ���������� ������ �������
    return true; // ���� ����� ������, �� ���������� true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() == b.get_apart()) and (a.get_surname() > b.get_surname())) { // ���� ������ ������� �����, �� ���������� �������
    return true; // ���� ����� ������, �� ���������� true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() == b.get_apart()) and (a.get_surname() == b.get_surname()) and (a.get_name() > b.get_name())) { // ���� ������� �����, �� ���������� �����
    return true; // ���� ����� ������, �� ���������� true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() == b.get_apart()) and (a.get_surname() == b.get_surname()) and (a.get_name() == b.get_name()) and (a.get_father() > b.get_father())) { // ���� ����� ����� �� ���������� ��������
    return true; // ���� ����� ������, �� ���������� true
  }
  return false; // ����� ���������� false
}
bool operator==(const Citizen& a, const Citizen& b) { // ����������� �������� ��������� ==
  if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() == b.get_apart()) and (a.get_surname() == b.get_surname()) and (a.get_name() == b.get_name()) and (a.get_father() == b.get_father())) return true; // ���� ��� ���� �������� �����, �� ���������� true
  return false; // ����� - flase
}
bool operator>=(const Citizen& a, const Citizen& b) { // ����������� �������� >=
  if (a > b || a == b) return true; // ���� ����� ������ ������ ��� �����, �� ���������� true
  return false; // ����� ���������� false
}
bool operator<(const Citizen& a, const Citizen& b) { // ����������� �������� <
  if (a >= b) return false; // ���� ����� ������ ������ ��� �����, �� ���������� false
  return true; // ����� ���������� true
}
bool operator<=(const Citizen& a, const Citizen& b) { // ����������� �������� <=
  if (a > b) return false; // ���� ����� ������ ������, �� ���������� false
  return true; // ����� ���������� true
}
string Citizen::get_surname() const { return surname; } // �������, ������� ���������� �������� ������� ���� �������
string Citizen::get_name() const { return name; }
string Citizen::get_father()  const { return father; }
string Citizen::get_street()  const { return street; }
int Citizen::get_house()  const { return house; }
int Citizen::get_apart() const { return apart; }
int Citizen::get_year() const { return year; }

void createMass(Citizen* a) { // ���������� ������ ���������� �� ����� � ������
  string path = "C:\\333\\dataset.txt"; // ���� � ����� � ����� ������
  ifstream fin; // �������� ����������
  fin.open(path); // ��������� ����
  if (!fin.is_open()) { // ���� ���� �� ��������, �� ������ ������
    cout << "Error" << endl;
  }
  else { // ���� ��������, �� ������ ������ ������ � ������
    int i = 0; // �������
    string surname, name, father, street, house, apart, year; // ��� ��� ���� ���������, �� ��� ��������� �� ���� � ��������� ����������, ��������� �������������� � ������ ������
    while (!fin.eof()) { // ���� �� ����� ����� ��������� �� ���� ������
      getline(fin, street, '\t'); // ������ ��������� ����������, ������� ��������� ��� �����������
      getline(fin, house, '\t'); // ��������������� ��������� ��� ����� �� ����� ������
      getline(fin, apart, '\t'); // ���� ������ - ���� ������ � ��
      getline(fin, surname, '\t');
      getline(fin, name, '\t');
      getline(fin, father, '\t');
      getline(fin, year); // ����� ��������� ������� ���� ������ ��������� ������
      if(i < 10000) a[i].set(surname, name, father, street, stoi(house), stoi(apart), stoi(year)); // ��������� ��� �� �� ����� �� ������� ������� � ���������� � i-�� ���������� ��������� ��������
       // ������� std::stoi(string) ��������� ������ � ����� ����� (�� ��� ������������, � ��� ���������� �����, �������� ������ "45" ������ ����� ������ 45)
      i++; // ����������� �������
    }
  }
  fin.close(); // ��������� ����
}
void insert_sort(Citizen* a, const int start, const int n){ // ���������� ��������� ���������� ���������
   // ����� start - ���������� ����� ��������, � �������� �������� ����������, � n - ����� ������������ �������
  int i, j; // ��������
  Citizen value; // ���������� ������, � ������� �������� ����� ��������� �������� ����������� ��������
  for (i = start + 1; i < start + n; i++) // ������� �� 2 �������� � �� ����� �������� �� ������� �� n ���������
  {
    value = a[i]; // �������� i-��� �������� �� ��������� ����������
    for (j = i - 1; j >= start && a[j] > value; j--) // ����� ���������� �� ��� ��������������� ����� ������� ����� � ������� ���������� ��� i-���� �������� �����
    {
      a[j + 1] = a[j]; // �������� �� 1 ������ ��� �������� ��������������� ����� �������, ���� ��� ������ ������ i-���� ��������
    }
    a[j + 1] = value; // ����� ���������� ����� �������, �� ���������� ���� �������� ������ i-���� ��������
  }
}
void sheker_sort(Citizen* mass, const int start, const int n){ // ���������� ��������� ������-����������
  int left = start, right = start + n - 1; // ����� � ������ ������� ����������� ������� �������
  int flag = 1; // ���� ������� �����������
  // ��������� ���� ���� ����� � ������ ������� �� ���������� � ���� � ������� ������� �����������
  while ((left < right) && flag > 0) // ���� ����� ������� ������ ������ � ���� �������� ����� �����������������
  {
    flag = 0; // ������ ���� ������ 0
    for (int i = left; i < right; i++) // ��������� ����� �������
    {
      if (mass[i] > mass[i + 1]) // ���� ��������� ������� ������ ��������,
      { // ������ �� �������
        Citizen t = mass[i];
        mass[i] = mass[i + 1];
        mass[i + 1] = t;
        flag = 1; // ������ ���� ������ 1, ��� ����� ���������, ��� ��������� ����
      }
    }
    right--; // �������� ������ ������� �� ���� ������� �����
    for (int i = right; i > left; i--) // ��������� ������ ������
    {
      if (mass[i - 1] > mass[i]) // ���� ���������� ������� ������ ��������,
      { // ������ �� �������
        Citizen t = mass[i];
        mass[i] = mass[i - 1];
        mass[i - 1] = t;
        flag = 1; // ������ ���� ������ 1, ��� ����� ���������, ��� ��������� ����
      }
    }
    left++; // �������� ����� ������� �� ���� ������� ������
  }
}