#ifndef ASSIGNMENT_1__CONTACT_LIST_H_
#define ASSIGNMENT_1__CONTACT_LIST_H_

#include <vector>
#include <memory>
#include <iostream>
#include <tuple>
#include "contact.h"

/*
Add
Search
Delete
List
Quit
*/

class ContactList {
public:
	static ContactList parse(std::istream& file);
	
	explicit ContactList(std::vector<Contact> list)
		: _list(std::move(list))
	{}

	void encode(std::ostream& file) const;
	
	void push(Contact contact) {
		_list.push_back(std::move(contact));
	}
	
	bool exists(const Contact& contact) const;
	
	void delete_(const std::string& contact_name);
	
	size_t size() {
		return _list.size();
	}
	
	void output(std::ostream& out) const;
	
	bool operator==(const ContactList &rhs) const {
		return _list == rhs._list;
	}
private:
	std::vector<Contact> _list;
};

#endif //ASSIGNMENT_1__CONTACT_LIST_H_
