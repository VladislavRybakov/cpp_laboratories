#include"Contacts.h"

int main() {
	Contacts a, b;
	a = b;// проверка работы оператора = 

	std::cout << "empty?\n" << a.empty() << std::endl;
	std::cout << "size:\n" << a.size() << std::endl;
	std::cout << "Open file?(wrong name) " << a.fill_from_file("tex.txt") << std::endl;
	std::cout << "Open file?(true name) " << a.fill_from_file("C:\\333\\text.txt") << std::endl;
	for (auto it = a.begin(); it != a.end(); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}

	Contacts c1(a);// работа конструктора копирования
	std::cout << std::endl;
	for (auto it = c1.begin(); it != c1.end(); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}
	std::cout << "Size c1: " << c1.size() << std::endl;
	c1.clear();
	std::cout << "Size c1: " << c1.size() << std::endl;

	a.swap(c1); //как не статический метод свап
	std::cout << "a contains:" << std::endl;
	for (auto it = a.begin(); it != a.end(); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}
	std::cout << std::endl;
	std::cout << "c1 contains:" << std::endl;
	for (auto it = c1.begin(); it != c1.end(); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}
	Contacts::swap(a, c1); //как статический метод свап
	std::cout << std::endl;
	std::cout << "a contains:" << std::endl;
	for (auto it = a.begin(); it != a.end(); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}
	std::cout << std::endl;
	std::cout << "c1 contains :" << std::endl;
	for (auto it = c1.cbegin(); it != c1.cend(); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}
	auto ty = a.find("+78743577835");
	std::cout << "find +78743577835: ";
	std::cout << (*a.find("+78743577835")).second.first << " ";
	std::cout << (*a.find("+78743577835")).second.second << std::endl;
	std::cout << "range +79234234134: " << (*(a.range("+79234234134")).first).first << " " << (*(a.range("+79234234134")).first).second.first << " " << (*(a.range("+79234234134")).first).second.second << " ^:^ " << (*(a.range("+79234234134")).second).first << " " << (*(a.range("+79234234134")).second).second.first << " " << (*(a.range("+79234234134")).second).second.second;
	a.erase("+78743577835");
	std::cout << std::endl;
	std::cout << std::endl;
	for (auto it = a.begin(); it != (a.end()); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}
	std::cout << std::endl;
	auto tu = a.at("+79234234134");
	a.insert("+78743577835", std::make_pair("4.4.1990", "jfdkgjdkfgjkkdjfgkjdkj"));
	for (auto it = a.begin(); it != (a.end()); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	a.insert_or_assign("+78743577835", std::make_pair("6.6.6666", "uutuutututuutut"));
	for (auto it = a.begin(); it != (a.end()); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}
	/*b.fill_from_file("C:\\333\\text1.txt");
	for (auto it = a.begin(); it != (a.end()); ++it) {
		std::cout << (*it).first << " ";
		std::cout << (*it).second.first << " ";
		std::cout << (*it).second.second << std::endl;
	}*/
}