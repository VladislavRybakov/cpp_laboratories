#include "List.h"
#include "Time.h"

int main()
{
  List<Time> head;
  Time sto(59, 59);
  head.createList();
  head.printList();
  std::cout << "\nAdd head 59:59:";
  head.add_head(sto);
  head.printList();
  std::cout << "\nDelete head:";
  head.delete_head();
  head.printList();
  std::cout << "\nDelete tail:";
  head.delete_tail();
  head.printList();
  std::cout << "\nAdd 59:59 in 10 position:";
  head.add_pos(sto, 10);
  head.printList();
  std::cout << "\nAdd 59:59 in 2 position:";
  head.add_pos(sto, 2);
  head.printList();
  std::cout << "\nDelete -1 position:";
  head.delete_pos(-1);
  head.printList();
  std::cout << "\nDelete 3 position:";
  head.delete_pos(3);
  head.printList();
  std::cout << "\nChange 2 and 4 positions:";
  head.change(2, 4);
  head.printList();
  std::cout << "\nChange 2 and 20 positions:";
  head.change(2, 20);
  head.printList();
}