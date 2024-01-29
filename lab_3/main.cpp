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

  it = myList.begin(); // после первого элемента вставим другой
  myList.insert_after(it, one);

  std::cout << "\nYour new list:\n";
  for (it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << '\n';
  }

  it = myList.begin(); // удалим второй элемент
  myList.erase_after(it);

  std::cout << "\nYour new list:\n";
  for (it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << '\n';
  }

  it = myList.end(); // попробуем удалить конец списка
  std::cout << "\nTry to erase after end of list: ";
  myList.erase_after(it);

  it = myList.begin();
  Iterator<Time> it2 = myList.createIterator();
  it++; // поставим первый итератор на 2-ой элемент
  it2++;
  it2++;
  it2++;  // второй итератор на 4-й элемент
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