#pragma once // для того, чтобы заголовочник не подключался больше 1 раза
#include <string>
using namespace std;

class Citizen
{
private: // приватные поля
  string surname; // фамилия
  string name; // имя
  string father; // отчество
  string street; // улица
  int house; // номер дома
  int apart; // номер квартиры
  int year; // год рождения
public:
  Citizen() = default; // конструктор по умолчанию
  Citizen(const Citizen &a); // конструктор копирования
  Citizen(const string surname, const string name, const string father, const string street, const int house, const int apart, const int year); // конструктор со всеми аргументами
  void set(const string surname, const string name, const string father, const string street, const int house, const int apart, const int year); // сеттер для сразу всех полей класса
  string get_surname() const; // геттер для фамилии
  string get_name() const; // геттер для имени
  string get_father() const; // геттер для отчества
  string get_street() const; // геттер для улицы
  int get_house() const; // геттер для номера дома
  int get_apart() const; // геттер для номера квартиры
  int get_year() const; // геттер для года рождения
  Citizen& operator=(const Citizen &a); // перегрузка оператора присваивания
  friend bool operator>(const Citizen& a, const Citizen& b); // перегрузка операторов сравнения
  friend bool operator==(const Citizen& a, const Citizen& b);
  friend bool operator>=(const Citizen& a, const Citizen& b);
  friend bool operator<(const Citizen& a, const Citizen& b);
  friend bool operator<=(const Citizen& a, const Citizen& b);
};
// прототипы функций
void createMass(Citizen* a); // функция заполнения массива данными из файла
void insert_sort(Citizen* a, const int start, const int n); // сортировка вставками
void sheker_sort(Citizen* mass, const int start, const int n); // шейкер-сортировка 