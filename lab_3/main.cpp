#include "Time.h"
#include "List.h"
#include "Iterator.h"

int main()
{
  List<Time> myList;
  Time one(1, 1);
  myList.createList();

  Iterator<Time> it = myList.createIterator();
  std::cout << "\nYour list:\n";
  for (it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << '\n';
  }

  it = myList.begin(); // ����� ������� �������� ������� ������
  myList.insert_after(it, one);

  std::cout << "\nYour new list:\n";
  for (it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << '\n';
  }

  it = myList.begin(); // ������ ������ �������
  myList.erase_after(it);

  std::cout << "\nYour new list:\n";
  for (it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << '\n';
  }

  it = myList.end(); // ��������� ������� ����� ������
  std::cout << "\nTry to erase after end of list: ";
  myList.erase_after(it);

  it = myList.begin();
  Iterator<Time> it2 = myList.createIterator();
  it++; // �������� ������ �������� �� 2-�� �������
  it2++;
  it2++;
  it2++;  // ������ �������� �� 4-� �������
  myList.erase_after(it, it2);

  std::cout << "\nYour new list:\n";
  for (it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << '\n';
  }

  //List<Time> myNewList;
  //myNewList.createList();

  //List<Time>::swap(myList, myNewList);

  //myList.printList();
  //myNewList.printList();
}