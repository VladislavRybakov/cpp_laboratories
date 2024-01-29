#pragma once
#include "Node.h"
#include "Iterator.h"
#include <exception>

template <typename abstracted>
class List
{
  Node<abstracted>* head;
public:
  List() : head(NULL) {}

  Iterator<abstracted>& createIterator() const {
    Iterator<abstracted> it(head);
    return it;
  }

  Iterator<abstracted> begin() const {
    Iterator<abstracted> it(head);
    return it;
  }

  Iterator<abstracted> end() const {
    Iterator<abstracted> it(NULL);
    return it;
  }

  Iterator<abstracted> insert_after(const Iterator<abstracted>& it, const abstracted& val) const {
    if (it.container == NULL) {
      std::cout << "You can not insert here!\n";
      return Iterator<abstracted>(NULL);
    }
    Node<abstracted>* tmp = new Node<abstracted>(val);
    tmp->next = it.container->next;
    it.container->next = tmp;
    return Iterator<abstracted>(tmp);
  }

  Iterator<abstracted> erase_after(const Iterator<abstracted>& it) const {
    //if (it.container == NULL || it.container->next == NULL) {
    //  std::cout << "Nothing to delete!\n";
    //  return Iterator<abstracted>(NULL);
    //}
    try {
      it.container->next;
      it.container->next->next;
      std::cout << "\n\naaaaaaaaaaaaaaaaaaaaaaaaa\n\n";
    }
    catch (const std::exception &ex) {
      std::cout << "Nothing to delete!\n";
      return Iterator<abstracted>(NULL);
    }
    Node<abstracted>* tmp = it.container->next;
    it.container->next = tmp->next;
    delete tmp;
    return Iterator<abstracted>(it.container->next);
  }

  Iterator<abstracted> erase_after(const Iterator<abstracted>& first, const Iterator<abstracted>& last) const {
    Node<abstracted>* tmp = first.container->next;
    if (first.container == NULL || first.container->next == NULL) {
      std::cout << "Nothing to delete!\n";
      return Iterator<abstracted>(NULL);
    }
    first.container->next = last.container->next;
    last.container->next = NULL;
    Node<abstracted>* p;
    for (; tmp != NULL;) {
      p = tmp->next;
      delete tmp;
      tmp = p;
    }
    return first;
  }

  bool empty() const {
    if (begin() == end()) return true;
    return false;
  }

  static void swap(List<abstracted>& L1, List<abstracted>& L2) {
    Node<abstracted>* tmp = L1.head;
    L1.head = L2.head;
    L2.head = tmp;
  }

  void add_head(const abstracted& one) {
    if (head == NULL) {
      head = new Node<abstracted>(one);
      return;
    }
    Node<abstracted>* tmp = new Node<abstracted>(one);
    tmp->next = head;
    head = tmp;
  }

  void add_tail(const abstracted &one) {
    if (head == NULL) {
      head = new Node<abstracted>(one);
      return;
    }
    Node<abstracted>* tmp = head;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new Node<abstracted>(one);
  }

  void printList() const {
    Node<abstracted>* tmp = head;
    std::cout << "\nYour list:\n";
    if (tmp == NULL || tmp->data == NULL && tmp->next == NULL) { // проверка на пустоты списка
      std::cout << "\nList is empty!\n";
      return;
    }
    for (tmp = head; tmp != NULL; tmp = tmp->next) std::cout << tmp->data << '\n';
  }

  void createList() {
    int n;
    abstracted data;
    Node<abstracted> *tmp;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    if (n <= 0) { // проверка на некорректный ввод
      std::cout << "\nWrong enter!\n";
      return;
    }
    std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
      std::cin >> data;
      add_tail(data);
    }
  }

  void delete_head() {
    if (head->next == NULL) {
      delete head;
      head = NULL;
    }
    else {
      Node<abstracted>* tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  void delete_tail() {
    if (head->next == NULL) {
      delete head;
      head = NULL;
    }
    else {
      Node<abstracted>* tmp = head;
      for (; (tmp->next)->next != NULL; tmp = tmp->next);
      delete (tmp->next);
      tmp->next = NULL;
    }
  }

  ~List() {
    while (head != NULL) delete_head();
  }
};