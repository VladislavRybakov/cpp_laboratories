#pragma once
#include<iostream>
#include <map>
#include <iterator>

struct cmp {
	bool operator() (const std::string& p1, const std::string& p2)const {
		return (p1 < p2);
	}
};

using value_type = std::string;
using phone_type = std::string;
using date_type = std::string;

class Contacts {
	std::map <value_type, std::pair <phone_type, date_type>, cmp> contacts;
public:
	Contacts() = default;

	Contacts(std::initializer_list <std::map < value_type, std::pair<phone_type, date_type>>> init);


	Contacts& operator=(const Contacts& a);
	Contacts(std::map <value_type, std::pair <phone_type, date_type>>::iterator first, std::map <value_type, std::pair <phone_type, date_type>>::iterator last);
	Contacts(Contacts& a);
	bool empty();
	size_t size();
	void clear();
	void swap(Contacts& book);
	static void swap(Contacts& book1, Contacts& book2);

	std::map<value_type, std::pair <phone_type, date_type>>::iterator begin();
	std::map<value_type, std::pair <phone_type, date_type>>::iterator end();
	const std::map<value_type, std::pair <phone_type, date_type>>::iterator cbegin();
	const std::map<value_type, std::pair <phone_type, date_type>>::iterator cend();
	const std::pair <phone_type, date_type>& at(value_type a);
	std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> insert(value_type a, std::pair<phone_type, date_type> b);
	std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, bool> insert_or_assign(value_type a, std::pair<phone_type, date_type> b);
	std::map<value_type, std::pair <phone_type, date_type>>::iterator find(value_type a);
	std::pair<std::map<value_type, std::pair <phone_type, date_type>>::iterator, std::map<value_type, std::pair <phone_type, date_type>>::iterator> range(value_type a);

	bool erase(value_type a);

	std::pair <phone_type, date_type>& operator[] (value_type a);
	bool fill_from_file(std::string str);
};
