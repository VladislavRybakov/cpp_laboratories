#pragma once // ��� ����, ����� ������������ �� ����������� ������ 1 ����
#include <string>
using namespace std;

class Citizen
{
private: // ��������� ����
  string surname; // �������
  string name; // ���
  string father; // ��������
  string street; // �����
  int house; // ����� ����
  int apart; // ����� ��������
  int year; // ��� ��������
public:
  Citizen() = default; // ����������� �� ���������
  Citizen(const Citizen &a); // ����������� �����������
  Citizen(const string surname, const string name, const string father, const string street, const int house, const int apart, const int year); // ����������� �� ����� �����������
  void set(const string surname, const string name, const string father, const string street, const int house, const int apart, const int year); // ������ ��� ����� ���� ����� ������
  string get_surname() const; // ������ ��� �������
  string get_name() const; // ������ ��� �����
  string get_father() const; // ������ ��� ��������
  string get_street() const; // ������ ��� �����
  int get_house() const; // ������ ��� ������ ����
  int get_apart() const; // ������ ��� ������ ��������
  int get_year() const; // ������ ��� ���� ��������
  Citizen& operator=(const Citizen &a); // ���������� ��������� ������������
  friend bool operator>(const Citizen& a, const Citizen& b); // ���������� ���������� ���������
  friend bool operator==(const Citizen& a, const Citizen& b);
  friend bool operator>=(const Citizen& a, const Citizen& b);
  friend bool operator<(const Citizen& a, const Citizen& b);
  friend bool operator<=(const Citizen& a, const Citizen& b);
};
// ��������� �������
void createMass(Citizen* a); // ������� ���������� ������� ������� �� �����
void insert_sort(Citizen* a, const int start, const int n); // ���������� ���������
void sheker_sort(Citizen* mass, const int start, const int n); // ������-���������� 