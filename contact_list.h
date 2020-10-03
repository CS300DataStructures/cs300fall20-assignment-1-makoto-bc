#ifndef ASSIGNMENT_1__CONTACT_LIST_H_
#define ASSIGNMENT_1__CONTACT_LIST_H_

#include <vector>
#include <memory>
#include "contact.h"

class ContactList {
public:
	static ContactList parse(std::ifstream& file);
private:
	std::vector<Contact> list;
};

#endif //ASSIGNMENT_1__CONTACT_LIST_H_
