#ifndef ASSIGNMENT_1__CONTACT_LIST_H_
#define ASSIGNMENT_1__CONTACT_LIST_H_

#include <vector>
#include <memory>
#include <iostream>
#include <tuple>
#include "contact.h"

/**
 * An ordered list of Contacts.
 */
class ContactList {
public:
	/**
	 * Parses phonebook file.
	 */
	static ContactList parse(std::istream& file);
	
	explicit ContactList(std::vector<Contact> list)
		: _list(std::move(list))
	{}

	/**
	 * Encodes ContactList in a machine readable format.
	 * @param file The phonebook file
	 */
	void encode(std::ostream& file) const;

	/**
	 * Formats this list for user-facing output.
	 * @param out Stream to write to 
	 */
	void output(std::ostream& out) const;
	
	/**
	 * Adds contact to the end of this list.
	 */
	void push(Contact contact) {
		_list.push_back(std::move(contact));
	}
	
	/** 
	 * @return true if an entry that equals given contact exists.  
	 */
	bool exists(const Contact& contact) const;
	
	/**
	 * Deletes all contacts with given contact name.
	 */
	void delete_(const std::string& contact_name);
	
	/**
	 * @return The size of this list. 
	 */
	size_t size() {
		return _list.size();
	}
	
	bool operator==(const ContactList &rhs) const {
		return _list == rhs._list;
	}
private:
	std::vector<Contact> _list;
};

#endif //ASSIGNMENT_1__CONTACT_LIST_H_
