#include "citizen.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


Citizen::Citizen(const string surname, const string name, const string father, const string street, const int house, const int apart, const int year) { // реализация конструктора со всеми аргументами
  this->surname = surname; // присваиваем полям объекта соответствующие полученные значения
  this->name = name;
  this->father = father;
  this->street = street;
  this->house = house;
  this->apart = apart;
  this->year = year;
}
void Citizen::set(const string surname, const string name, const string father, const string street, const int house, const int apart, const int year) { // реализация сеттера
  this->surname = surname; // присваиваем полям объекта соответствующие полученные значения
  this->name = name;
  this->father = father;
  this->street = street;
  this->house = house;
  this->apart = apart;
  this->year = year;
}
Citizen::Citizen(const Citizen& a) { // реализация конструктора копирования
  this->surname = a.get_surname(); // полям созданного объекта присваиваем значения полей полученного на вход объекта с помощью геттеров
  this->name = a.get_name();
  this->father = a.get_father();
  this->street = a.get_street();
  this->house = a.get_house();
  this->apart = a.get_apart();
  this->year = a.get_year();
}
Citizen& Citizen::operator=(const Citizen& a) { // реализация перегрузки оператора присваивания
  this->surname = a.get_surname(); // полям созданного объекта присваиваем значения полей полученного на вход объекта с помощью геттеров
  this->name = a.get_name();
  this->father = a.get_father();
  this->street = a.get_street();
  this->house = a.get_house();
  this->apart = a.get_apart();
  this->year = a.get_year();
  return *this; //возвращаем ссылку на текущий объект
}
bool operator>(const Citizen& a, const Citizen& b) { // реализация перегрузки оператора > (по условию приоритета сравнения полей из варианта лабораторной работы)
  if (a.get_street() > b.get_street()) { // сравниваем улицы двух объектов в лексикографическом порядке
    return true; // если левая больше, то возвращаем true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() > b.get_house())) { // если улицы одинаковые, сравниваем номер домов
    return true; // если левая больше, то возвращаем true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() > b.get_apart())) { // если номера домов равные сравниваем номера квартир
    return true; // если левая больше, то возвращаем true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() == b.get_apart()) and (a.get_surname() > b.get_surname())) { // если номера квартир равны, то сравниваем фамилии
    return true; // если левая больше, то возвращаем true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() == b.get_apart()) and (a.get_surname() == b.get_surname()) and (a.get_name() > b.get_name())) { // если фамилии равны, то сравниваем имена
    return true; // если левая больше, то возвращаем true
  }
  else if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() == b.get_apart()) and (a.get_surname() == b.get_surname()) and (a.get_name() == b.get_name()) and (a.get_father() > b.get_father())) { // если имена равны то сравниваем отчества
    return true; // если левая больше, то возвращаем true
  }
  return false; // иначе возвращаем false
}
bool operator==(const Citizen& a, const Citizen& b) { // перегружаем оператор сравнения ==
  if ((a.get_street() == b.get_street()) and (a.get_house() == b.get_house()) and (a.get_apart() == b.get_apart()) and (a.get_surname() == b.get_surname()) and (a.get_name() == b.get_name()) and (a.get_father() == b.get_father())) return true; // если все поля объектов равны, то возвращаем true
  return false; // иначе - flase
}
bool operator>=(const Citizen& a, const Citizen& b) { // перегружаем оператор >=
  if (a > b || a == b) return true; // если левый объект больше или равен, то возвращаем true
  return false; // иначе возвращаем false
}
bool operator<(const Citizen& a, const Citizen& b) { // перегружаем оператор <
  if (a >= b) return false; // если левый объект больше или равен, то возвращаем false
  return true; // иначе возвращаем true
}
bool operator<=(const Citizen& a, const Citizen& b) { // перегружаем оператор <=
  if (a > b) return false; // если левый объект больше, то возвращаем false
  return true; // иначе возвращаем true
}
string Citizen::get_surname() const { return surname; } // геттеры, которые возвращают значение нужного поля объекта
string Citizen::get_name() const { return name; }
string Citizen::get_father()  const { return father; }
string Citizen::get_street()  const { return street; }
int Citizen::get_house()  const { return house; }
int Citizen::get_apart() const { return apart; }
int Citizen::get_year() const { return year; }

void createMass(Citizen* a) { // реализация записи информации из файла в массив
  string path = "C:\\333\\dataset.txt"; // путь к файлу с базой данных
  ifstream fin; // файловая переменная
  fin.open(path); // открываем файл
  if (!fin.is_open()) { // если файл не открылся, то выдаем ошибку
    cout << "Error" << endl;
  }
  else { // если открылся, то делаем печать данных в массив
    int i = 0; // счетчик
    string surname, name, father, street, house, apart, year; // так как файл текстовый, то все считываем из него в строковые переменные, названные соответственно с полями класса
    while (!fin.eof()) { // пока не конец файла считываем из него строки
      getline(fin, street, '\t'); // строки разделены табуляцией, которую указываем как разделитель
      getline(fin, house, '\t'); // последовательно считываем все слова из одной строки
      getline(fin, apart, '\t'); // одна строка - одна запись в БД
      getline(fin, surname, '\t');
      getline(fin, name, '\t');
      getline(fin, father, '\t');
      getline(fin, year); // после последней строчки идет символ окончания строки
      if(i < 10000) a[i].set(surname, name, father, street, stoi(house), stoi(apart), stoi(year)); // проверяем что мы не вышли за пределы массива и записываем в i-ую переменную считанные значения
       // функция std::stoi(string) переводит строку в целое число (не как раскодировку, а как написанное число, например строка "45" станет целым числом 45)
      i++; // увеличиваем счетчик
    }
  }
  fin.close(); // закрываем файл
}
void insert_sort(Citizen* a, const int start, const int n){ // реализация алгоритма сортировки вставками
   // здесь start - порядковый номер элемента, с которого начинаем сортировку, а n - длина сортируемого массива
  int i, j; // счетчики
  Citizen value; // переменная класса, в которой временно будет храниться значение заменяемого элемента
  for (i = start + 1; i < start + n; i++) // начиная со 2 элемента и до конца проходим по массиву из n элементов
  {
    value = a[i]; // помещаем i-тое значение во временную переменную
    for (j = i - 1; j >= start && a[j] > value; j--) // далее проходимся по уже отсортированной части массива влево и находим подходящее для i-того элемента место
    {
      a[j + 1] = a[j]; // сдвигаем на 1 вправо все элементы отсортированной части массива, пока они больше нашего i-того элемента
    }
    a[j + 1] = value; // когда подходящее место найдено, то записываем туда значение нашего i-того элемента
  }
}
void sheker_sort(Citizen* mass, const int start, const int n){ // реализация алгоритма шейкер-сортировки
  int left = start, right = start + n - 1; // левая и правая границы сортируемой области массива
  int flag = 1; // флаг наличия перемещений
  // выполняем цикл пока левая и правая граница не сравняются и пока в массиве имеются перемещения
  while ((left < right) && flag > 0) // пока левая граница меньше правой и пока элементы стоят неотсортированные
  {
    flag = 0; // ставим флаг равным 0
    for (int i = left; i < right; i++) // двигаемся слева направо
    {
      if (mass[i] > mass[i + 1]) // если следующий элемент меньше текущего,
      { // меняем их местами
        Citizen t = mass[i];
        mass[i] = mass[i + 1];
        mass[i + 1] = t;
        flag = 1; // делаем флаг равным 1, тем самым показывая, что изменения были
      }
    }
    right--; // сдвигаем правую границу на один элемент влево
    for (int i = right; i > left; i--) // двигаемся справа налево
    {
      if (mass[i - 1] > mass[i]) // если предыдущий элемент больше текущего,
      { // меняем их местами
        Citizen t = mass[i];
        mass[i] = mass[i - 1];
        mass[i - 1] = t;
        flag = 1; // делаем флаг равным 1, тем самым показывая, что изменения были
      }
    }
    left++; // сдвигаем левую границу на один элемент вправо
  }
}