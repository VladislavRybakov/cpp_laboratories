#pragma once
#include <iostream>

template <typename abstracted>
class List
{
public:
  abstracted data; // переменная в которой хранится значение
  List* next; // указатель на следующий элемент списка
public:
  List() : next(NULL) {} // при создании элемента всегда указатель на следующий элемент делаем равным NULL

  explicit List(abstracted smth) : data(smth), next(NULL) {}

  ~List() { // деструктор (удаляет весь список)
    while (this->next != NULL) this->delete_tail(); // голова всегда в статической памяти, а остальные элементы в динамической, поэтому при удалении головы чистится сразу вся выделенная память
  }

  friend std::ostream& operator << (std::ostream& out, List& a) { // оператор вывода
    out << a.data << " "; // у типа abstracted должен быть перегружен оператор вывода
    return out;
  }

  friend std::istream& operator >> (std::istream& in, List& a) { // оператор ввода
    abstracted smt;
    in >> smt; // у типа abstracted должен быть перегружен оператор ввода
    a.data = smt;
    return in;
  }

  List& operator=(const List& a) { // оператор присваивания
    data = a.data;
    next = a.next;
    return *this;
  }

  void add_tail(abstracted one) { // добавление в хвост
    List* tmp = this;
    for (; tmp->next != NULL; tmp = tmp->next); // проходим указателем до конца списка
    tmp->next = new List(one); // добавляем в конец новый элемент
  }

  void add_head(abstracted one) { // добавление в голову
    if (this->data == NULL && this->next == NULL) { // если список пустой, то просто меняем значение головы
      this->data = one;
      return;
    }
    List* som = new List; // иначе создаем новый элемент
    *som = *this; // приравниваем его к прошлой голове
    this->data = one; // меняем старую голову, делая ее новой
    this->next = som;
  }

  void add_pos(abstracted one, int pos) { // добавление в нужную позицию
    if (pos < 0) { // проверка на отрицательную позицию
      std::cout << "\nWrong position!\n";
      return;
    }
    if (pos == 0) { // если позиция равна нулю, то добавляем в голову
      this->add_head(one);
      return;
    }
    List* tmp = this;
    int count = 1;
    for (; tmp->next != NULL; tmp = tmp->next) count++; // считаем количество элементов в списке
    if (pos > count) { // проверка если указанная позиция больше длины списка
      std::cout << "\nError. Position is more than list lenght.\n";
      return;
    }
    else if (pos == count) { // если элемент последний, то добавляем в хвост
      this->add_tail(one);
      return;
    }
    tmp = this;
    for (int i = 1; i < pos; tmp = tmp->next, i++); // иначе доходим до нужной позиции 
    List* p = new List(one); // выделяем память под новый элемент с заданным значением
    p->next = tmp->next; // вставляем его в нужное место
    tmp->next = p;
  }

  void printList() { // функция печати списка
    List tmp;
    std::cout << "\nYour list:\n";
    if (this->data == NULL && this->next == NULL) { // проверка на пустоты списка
      std::cout << "\nList is empty!\n";
      return;
    }
    for (tmp = *this; tmp.next != NULL; tmp = *tmp.next) std::cout << tmp; // печать списка (без последнего элемена)
    std::cout << tmp << std::endl; // печать последнего элемента списка
  }

  void createList() { // создание списка
    int n;
    abstracted a;
    List* tmp = this;
    std::cout << "Enter number of elements: ";
    std::cin >> n; // ввод количества элементов
    if (n <= 0) { // проверка на некорректный ввод
      std::cout << "\nWrong enter!\n";
      return;
    }
    std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
      std::cin >> a; // вводим n значений
      if (i == 0) data = a; // если голова - просто приравниваем ей значение
      else {
        tmp->add_tail(a); // добавляем в хвост
        tmp = tmp->next; // смещаемся на элемент вправо
      }
    }
  }

  void delete_head() { // удаление головы
    if (this->next == NULL) { // если список из одного элемента (головы), то зануляем ее значение
      this->data = NULL;
      return;
    }
    List* p = this->next; // иначе создаем указатель на первый элемент списка (нулевой - голова)
    *this = *(this->next); // приравниваем голове первый элемент списка
    p->next = NULL; // у прошлого первого элемента удаляем указатель на следующий, чтобы не удалить весь список
    delete p; // очищаем p
  }

  void delete_tail() { // удаление хвоста
    List* tmp = this;
    if (this->next == NULL) { // если голова - зануляем значение
      this->data = NULL;
      return;
    }
    for (; (tmp->next)->next != NULL; tmp = tmp->next); // двигаемся до предпоследнего элемента списка
    delete (tmp->next); // удаляем последний
    tmp->next = NULL; // зануляем указатель у предпоследнего
  }

  void delete_pos(int pos) { // удаление конкретной позиции
    if (pos < 0) { // проверка на некорректный ввод
      std::cout << "\nWrong position!\n";
      return;
    }
    if (pos == 0) { // проверка на удаление головы
      this->delete_head();
      return;
    }
    List* tmp = this;
    int count = 1;
    for (; tmp->next != NULL; tmp = tmp->next) count++; // считаем кол-во элементов списка
    if (pos >= count) { // проверка на выход за пределы списка
      std::cout << "\nError. Position is more than list lenght.\n";
      return;
    }
    else if (pos + 1 == count) { // проверка на удаление хвоста
      this->delete_tail();
      return;
    }
    tmp = this;
    for (int i = 1; i < pos; tmp = tmp->next, i++); // двигаемся до элемента с позицией pos-1
    List* p = tmp->next; // в p - удаляемый элемент
    tmp->next = tmp->next->next; // пропускаем p
    p->next = NULL; // зануляем у р указатель чтобы не стереть весь список
    delete p;
  }

  void deleteList() { // удаление листа (то же самое что и деструктор)
    while (this->next != NULL) this->delete_tail();
    this->data = NULL;
  }

  bool IsEmpty() { // проверка на пустоту
    if (this->next == NULL && this->data == NULL) return true; // если значение равно нулю и указатель на следующий отсутствует, то список считается пустым
    return false;
  }

  void change(const int& first, const int& second) { // обмен двух элементов списка
    if (first < 0 || second < 0) { // проверка на корректность ввода
      std::cout << "\nWrong position!\n";
      return;
    }
    List* tmp = this;
    int count = 1;
    for (; tmp->next != NULL; tmp = tmp->next) count++; // считаем кол-во лементов в списке
    if (first >= count || second >= count) { // проверка на выход за пределы списка
      std::cout << "\nError. Position is more than list lenght.\n";
      return;
    }
    List* tmp1 = this; // создаем два указателя, которые дойдут до нужных элементов
    tmp = this;
    for (int i = 1; i <= first; tmp = tmp->next, i++); // доходим до первого элемента
    for (int i = 1; i <= second; tmp1 = tmp1->next, i++); // доходим до второго элемента
    abstracted chng;
    chng = tmp->data;
    tmp->data = tmp1->data; // меняем значения этих двух элементов местами
    tmp1->data = chng;
  }
};
