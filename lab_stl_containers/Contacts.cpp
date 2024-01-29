#include "Contacts.h"
#include <fstream>

Contacts::Contacts(std::map<value_type, std::pair<phone_type, date_type>>::iterator first, std::map<value_type, std::pair<phone_type, date_type>>::iterator last)
{
	//++last;
	for (std::map<value_type, std::pair<phone_type, date_type>, cmp>::iterator it = first; it != last; it++) {
		this->contacts.insert(*it);
	}
}

Contacts::Contacts(Contacts& a) {
	this->contacts = a.contacts;
}

Contacts& Contacts::operator=(const Contacts& a)
{
	this->contacts = a.contacts;
	return *this;
}



bool Contacts::empty()
{
	return this->contacts.empty();
}

size_t Contacts::size()
{
	return this->contacts.size();
}

//Contacts::Contacts(std::initializer_list<value_type, std::pair<phone_type, date_type>> a)
//{
//	this->contacts = a;
//}

void Contacts::clear()
{
	this->contacts.clear();
}

void Contacts::swap(Contacts& book)
{
	Contacts temp = *this;
	*this = book;
	book = temp;
}

void Contacts::swap(Contacts& book1, Contacts& book2)
{
	Contacts temp = book2;
	book2 = book1;
	book1 = temp;
}

std::map<value_type, std::pair <phone_type, date_type>>::iterator Contacts::begin() {
	return this->contacts.begin();
}

std::map<value_type, std::pair<phone_type, date_type>>::iterator Contacts::end()
{
	return this->contacts.end();
}

const std::map<value_type, std::pair <phone_type, date_type>>::iterator Contacts::cbegin() {
	return this->contacts.begin();
}
const std::map<value_type, std::pair<phone_type, date_type>>::iterator Contacts::cend()
{
	return this->contacts.end();
}
const std::pair<phone_type, date_type>& Contacts::at(value_type a)
{
	return this->contacts.at(a);
}
std::pair <phone_type, date_type>& Contacts::operator[] (value_type a) {
	return this->contacts[a];
}

std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> Contacts::insert(value_type a, std::pair<phone_type, date_type> b) {
	bool flag = 1;
	if (b.first.size() == 13 && b.first[0] == '8' && b.first[4] == ' ' && b.first[8] == ' ') {

		for (size_t i = 0; i < 4; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 5; i < 8; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 9; i <= 12; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		if (flag) {
			b.first.erase(0);
			b.first.erase(3);
			b.first.erase(6);
			phone_type str = "+7";
			b.first = str + b.first;
			this->contacts.emplace(a, b);
			std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> g;
			g = this->contacts.emplace(a, b);
			return g;
		}
	}
	if (b.first.size() == 16 && b.first[2] == ' ' && b.first[0] == '+' && b.first[6] == ' ' && b.first[10] == ' ' && b.first[13] == ' ') {
		for (size_t i = 0; i < 2; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 3; i < 6; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 7; i < 10; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 11; i < 13; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 14; i < 16; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		if (flag) {
			b.first.erase(2);
			b.first.erase(5);
			b.first.erase(8);
			b.first.erase(10);
			std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> g;
			g = this->contacts.emplace(a, b);
			return g;
		}
	}
	if (b.first.size() == 12 && b.first[1] == ' ') {
		for (size_t i = 0; i < 1; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 2; i < 12; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		if (flag) {
			b.first.erase(1);
			phone_type str = "+";
			b.first = str + b.first;
			std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> g;
			g = this->contacts.emplace(a, b);
			return g;
		}
	}
	if (b.first.size() == 12 && b.first[3] == ' ' && b.first[7] == ' ') {
		for (size_t i = 0; i < 3; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 4; i < 7; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 8; i < 12; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		if (flag) {
			b.first.erase(3);
			b.first.erase(7);
			phone_type str = "+7";
			b.first = str + b.first;
			std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> g;
			g = this->contacts.emplace(a, b);
			return g;
		}
	}
	if (flag) return this->contacts.emplace(a, b);
	else
		std::cout << "error format data";
}

std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> Contacts::insert_or_assign(value_type a, std::pair<phone_type, date_type> b) {
	bool flag = 1;
	if (b.first.size() == 13 && b.first[0] == '8' && b.first[4] == ' ' && b.first[8] == ' ') {

		for (size_t i = 0; i < 4; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 5; i < 8; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 9; i <= 12; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		if (flag) {
			b.first.erase(0);
			b.first.erase(3);
			b.first.erase(6);
			phone_type str = "+7";
			b.first = str + b.first;
			this->contacts.emplace(a, b);
			std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> g;
			g = this->contacts.emplace(a, b);
			if (this->contacts[a] == b) {
				g.second = 1;
			}
			else {
				this->contacts[a] = b;
				g.second = 0;
			}
			return g;
		}
	}
	if (b.first.size() == 16 && b.first[2] == ' ' && b.first[0] == '+' && b.first[6] == ' ' && b.first[10] == ' ' && b.first[13] == ' ') {
		for (size_t i = 0; i < 2; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 3; i < 6; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 7; i < 10; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 11; i < 13; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 14; i < 16; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		if (flag) {
			b.first.erase(2);
			b.first.erase(5);
			b.first.erase(8);
			b.first.erase(10);
			std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> g;
			g = this->contacts.emplace(a, b);
			if (this->contacts[a] == b) {
				g.second = 1;
			}
			else {
				this->contacts[a] = b;
				g.second = 0;
			}
			return g;
		}
	}
	if (b.first.size() == 12 && b.first[1] == ' ') {
		for (size_t i = 0; i < 1; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 2; i < 12; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		if (flag) {
			b.first.erase(1);
			phone_type str = "+";
			b.first = str + b.first;
			std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> g;
			g = this->contacts.emplace(a, b);
			if (this->contacts[a] == b) {
				g.second = 1;
			}
			else {
				this->contacts[a] = b;
				g.second = 0;
			}
			return g;
		}
	}
	if (b.first.size() == 12 && b.first[3] == ' ' && b.first[7] == ' ') {
		for (size_t i = 0; i < 3; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 4; i < 7; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		for (size_t i = 8; i < 12; i++) {
			if (b.first[i] >= 48 && b.first[i] <= 57) {}
			else
				flag = 0;
		}
		if (flag) {
			b.first.erase(3);
			b.first.erase(7);
			phone_type str = "+7";
			b.first = str + b.first;
			std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> g;

		}
	}
	if (flag) {
		auto g = this->contacts.emplace(a, b);
		if (this->contacts[a] == b) {
			g.second = 1;
		}
		else {
			this->contacts[a] = b;
			g.second = 0;
		}
		return g;
	}
	else
		std::cout << "error format data";
}

std::map<value_type, std::pair <phone_type, date_type>>::iterator Contacts::find(value_type a) {
	return this->contacts.find(a);
}
std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, std::map<value_type, std::pair <phone_type, date_type>>::iterator> Contacts::range(value_type a) {
	return this->contacts.equal_range(a);
}
bool Contacts::erase(value_type a) {
	return this->contacts.erase(a);
}

bool Contacts::fill_from_file(std::string str) {
	std::string s1, s2, s3;
	std::ifstream file(str);
	std::map <value_type, std::pair <phone_type, date_type>, cmp> contacts1;
	if (!(file.is_open()))
		return 0;
	else
	{
		while (!file.eof()) {
			s1 = ""; s2 = ""; s3 = "";
			file >> s1; file >> s2; file >> s3;
			contacts1.emplace(s1, make_pair(s2, s3));
		}
	}
	file.close();
	this->contacts = contacts1;
	return 1;
}

void MergeMaps(std::map<value_type, std::pair <phone_type, date_type>, cmp>& lhs, const std::map<value_type, std::pair <phone_type, date_type>>& rhs) {
	std::map<value_type, std::pair <phone_type, date_type>, cmp>::iterator lhsItr = lhs.begin();
	std::map<value_type, std::pair <phone_type, date_type>>::const_iterator rhsItr = rhs.begin();

	while (lhsItr != lhs.end() && rhsItr != rhs.end()) {
		if (rhsItr->first < lhsItr->first) {
			lhs.insert(lhsItr, *rhsItr);
			++rhsItr;
		}
		else if (rhsItr->first == lhsItr->first) {
			lhsItr->second = rhsItr->second;
			++lhsItr; ++rhsItr;
		}
		else
			++lhsItr;

	}
	lhs.insert(rhsItr, rhs.end());
}

Contacts::Contacts(std::initializer_list<std::map<value_type, std::pair<phone_type, date_type>>> init)
{
	for (auto i = init.begin(); i != init.end(); i++) {
		MergeMaps(this->contacts, *i);
	}
}
