#ifndef ASSIGNMENT_1__CONTACT_LIST_H_
#define ASSIGNMENT_1__CONTACT_LIST_H_

#include <vector>
#include <memory>
#include <iostream>
#include <tuple>
#include "contact.h"

class ContactList {
public:
	static ContactList parse(std::istream& file);
	
	ContactList()
	{}
	
	ContactList(std::vector<Contact> list)
		: _list(std::move(list))
	{}
	
	void push(Contact contact) {
		_list.push_back(std::move(contact));
	}
	
	bool operator==(const ContactList &rhs) const {
		return _list == rhs._list;
	}
private:
	std::vector<Contact> _list;
};

#endif //ASSIGNMENT_1__CONTACT_LIST_H_
