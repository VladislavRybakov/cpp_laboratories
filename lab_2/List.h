#pragma once
#include <iostream>

template <typename abstracted>
class List
{
public:
  abstracted data; // ���������� � ������� �������� ��������
  List* next; // ��������� �� ��������� ������� ������
public:
  List() : next(NULL) {} // ��� �������� �������� ������ ��������� �� ��������� ������� ������ ������ NULL

  explicit List(abstracted smth) : data(smth), next(NULL) {}

  ~List() { // ���������� (������� ���� ������)
    while (this->next != NULL) this->delete_tail(); // ������ ������ � ����������� ������, � ��������� �������� � ������������, ������� ��� �������� ������ �������� ����� ��� ���������� ������
  }

  friend std::ostream& operator << (std::ostream& out, List& a) { // �������� ������
    out << a.data << " "; // � ���� abstracted ������ ���� ���������� �������� ������
    return out;
  }

  friend std::istream& operator >> (std::istream& in, List& a) { // �������� �����
    abstracted smt;
    in >> smt; // � ���� abstracted ������ ���� ���������� �������� �����
    a.data = smt;
    return in;
  }

  List& operator=(const List& a) { // �������� ������������
    data = a.data;
    next = a.next;
    return *this;
  }

  void add_tail(abstracted one) { // ���������� � �����
    List* tmp = this;
    for (; tmp->next != NULL; tmp = tmp->next); // �������� ���������� �� ����� ������
    tmp->next = new List(one); // ��������� � ����� ����� �������
  }

  void add_head(abstracted one) { // ���������� � ������
    if (this->data == NULL && this->next == NULL) { // ���� ������ ������, �� ������ ������ �������� ������
      this->data = one;
      return;
    }
    List* som = new List; // ����� ������� ����� �������
    *som = *this; // ������������ ��� � ������� ������
    this->data = one; // ������ ������ ������, ����� �� �����
    this->next = som;
  }

  void add_pos(abstracted one, int pos) { // ���������� � ������ �������
    if (pos < 0) { // �������� �� ������������� �������
      std::cout << "\nWrong position!\n";
      return;
    }
    if (pos == 0) { // ���� ������� ����� ����, �� ��������� � ������
      this->add_head(one);
      return;
    }
    List* tmp = this;
    int count = 1;
    for (; tmp->next != NULL; tmp = tmp->next) count++; // ������� ���������� ��������� � ������
    if (pos > count) { // �������� ���� ��������� ������� ������ ����� ������
      std::cout << "\nError. Position is more than list lenght.\n";
      return;
    }
    else if (pos == count) { // ���� ������� ���������, �� ��������� � �����
      this->add_tail(one);
      return;
    }
    tmp = this;
    for (int i = 1; i < pos; tmp = tmp->next, i++); // ����� ������� �� ������ ������� 
    List* p = new List(one); // �������� ������ ��� ����� ������� � �������� ���������
    p->next = tmp->next; // ��������� ��� � ������ �����
    tmp->next = p;
  }

  void printList() { // ������� ������ ������
    List tmp;
    std::cout << "\nYour list:\n";
    if (this->data == NULL && this->next == NULL) { // �������� �� ������� ������
      std::cout << "\nList is empty!\n";
      return;
    }
    for (tmp = *this; tmp.next != NULL; tmp = *tmp.next) std::cout << tmp; // ������ ������ (��� ���������� �������)
    std::cout << tmp << std::endl; // ������ ���������� �������� ������
  }

  void createList() { // �������� ������
    int n;
    abstracted a;
    List* tmp = this;
    std::cout << "Enter number of elements: ";
    std::cin >> n; // ���� ���������� ���������
    if (n <= 0) { // �������� �� ������������ ����
      std::cout << "\nWrong enter!\n";
      return;
    }
    std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
      std::cin >> a; // ������ n ��������
      if (i == 0) data = a; // ���� ������ - ������ ������������ �� ��������
      else {
        tmp->add_tail(a); // ��������� � �����
        tmp = tmp->next; // ��������� �� ������� ������
      }
    }
  }

  void delete_head() { // �������� ������
    if (this->next == NULL) { // ���� ������ �� ������ �������� (������), �� �������� �� ��������
      this->data = NULL;
      return;
    }
    List* p = this->next; // ����� ������� ��������� �� ������ ������� ������ (������� - ������)
    *this = *(this->next); // ������������ ������ ������ ������� ������
    p->next = NULL; // � �������� ������� �������� ������� ��������� �� ���������, ����� �� ������� ���� ������
    delete p; // ������� p
  }

  void delete_tail() { // �������� ������
    List* tmp = this;
    if (this->next == NULL) { // ���� ������ - �������� ��������
      this->data = NULL;
      return;
    }
    for (; (tmp->next)->next != NULL; tmp = tmp->next); // ��������� �� �������������� �������� ������
    delete (tmp->next); // ������� ���������
    tmp->next = NULL; // �������� ��������� � ��������������
  }

  void delete_pos(int pos) { // �������� ���������� �������
    if (pos < 0) { // �������� �� ������������ ����
      std::cout << "\nWrong position!\n";
      return;
    }
    if (pos == 0) { // �������� �� �������� ������
      this->delete_head();
      return;
    }
    List* tmp = this;
    int count = 1;
    for (; tmp->next != NULL; tmp = tmp->next) count++; // ������� ���-�� ��������� ������
    if (pos >= count) { // �������� �� ����� �� ������� ������
      std::cout << "\nError. Position is more than list lenght.\n";
      return;
    }
    else if (pos + 1 == count) { // �������� �� �������� ������
      this->delete_tail();
      return;
    }
    tmp = this;
    for (int i = 1; i < pos; tmp = tmp->next, i++); // ��������� �� �������� � �������� pos-1
    List* p = tmp->next; // � p - ��������� �������
    tmp->next = tmp->next->next; // ���������� p
    p->next = NULL; // �������� � � ��������� ����� �� ������� ���� ������
    delete p;
  }

  void deleteList() { // �������� ����� (�� �� ����� ��� � ����������)
    while (this->next != NULL) this->delete_tail();
    this->data = NULL;
  }

  bool IsEmpty() { // �������� �� �������
    if (this->next == NULL && this->data == NULL) return true; // ���� �������� ����� ���� � ��������� �� ��������� �����������, �� ������ ��������� ������
    return false;
  }

  void change(const int& first, const int& second) { // ����� ���� ��������� ������
    if (first < 0 || second < 0) { // �������� �� ������������ �����
      std::cout << "\nWrong position!\n";
      return;
    }
    List* tmp = this;
    int count = 1;
    for (; tmp->next != NULL; tmp = tmp->next) count++; // ������� ���-�� �������� � ������
    if (first >= count || second >= count) { // �������� �� ����� �� ������� ������
      std::cout << "\nError. Position is more than list lenght.\n";
      return;
    }
    List* tmp1 = this; // ������� ��� ���������, ������� ������ �� ������ ���������
    tmp = this;
    for (int i = 1; i <= first; tmp = tmp->next, i++); // ������� �� ������� ��������
    for (int i = 1; i <= second; tmp1 = tmp1->next, i++); // ������� �� ������� ��������
    abstracted chng;
    chng = tmp->data;
    tmp->data = tmp1->data; // ������ �������� ���� ���� ��������� �������
    tmp1->data = chng;
  }
};
