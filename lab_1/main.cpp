#include <iostream> //����������� ����������
#include <string> // ���������� ��� �����
#include <fstream>  // ���������� ��� ������ � �������
#include <ctime> // ���������� ��� ������ � ��������
#include "citizen.h" // ����������� ������������� ����� � ����������� ������ � ����������� �������
using namespace std; // ������������� ������������ ����

#define TICK(X) clock_t X = clock() // � ���������� � ������ ��������� �����
#define TOCK(X) printf("Time: %g sec.\n", (double)(clock() - (X)) / CLOCKS_PER_SEC) // ������� ������� ����� ��������� � ���������� �������� � ���������� � (g - ���������� ������������� ����� � ��������� ������)

int main()
{
  Citizen* one = new Citizen[10000]; // �������� ������ ��� ������� �� 10000 ���������
  createMass(one); // ������� ���������� ������� ������� �� �����
  int n, ch;  // ���������� ��� ���������� ����������� ��������� � ��� ������ ��������� ����������
  cout << "Enter number of lines: ";
  cin >> n;
  cout << "Choose sort method:\n(1) Insert sort\n(2) Sheker sort\nYour choice: "; // ����� ����
  cin >> ch;
  switch (ch) { 
  case 1: // ������ ������ ���������� ���������
    cout << "\nTime of 6 different datasets:\n";
    for (int i = 0; i < 6; i++) { // ������� ���������� ��� 6 ������ ������� ������ �� n ��������� � ������
      if (i * n + n < 10000) { // ���������, ��� �� �� ������ �� ����� �������
        cout << i + 1 << " dataset "; // ���������� ����� ��������
        TICK(Time); // �������� �����
        insert_sort(one, i * n, n); // ��������� ����������. i*n - ��������� ������� ������������ �������, �� ���� �� ��������� ������ n ���������, ����� ��������� n ��������� � ��� �����
        //����� ������� �� ������ ���������� ������ ������� ������, ��������� ���� ������� �������
        TOCK(Time); // ������� ����������� ����� �� �����
      }
    }
    break;
  case 2: // ������ ������ ������-����������
    cout << "\nTime of 6 different datasets:\n";
    for (int i = 0; i < 6; i++) {
      if (i * n + n < 10000) { // ���������, ��� �� �� ������ �� ����� �������
        cout << i << " dataset ";
        TICK(Time); // ��������� �����
        sheker_sort(one, i * n, n); // ��������� ����������. i*n - ��������� ������� ������������ �������, �� ���� �� ��������� ������ n ���������, ����� ��������� n ��������� � ��� �����
        //����� ������� �� ������ ���������� ������ ������� ������, ��������� ���� ������� �������
        TOCK(Time); // ������� �����
      }
    }
    break;
  }
  delete [] one; // ����������� ������� ������ ����� ��������� ������
}