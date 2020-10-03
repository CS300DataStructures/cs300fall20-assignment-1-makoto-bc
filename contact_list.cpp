#include "contact_list.h"

ContactList ContactList::parse(std::istream& file) {
	ContactList result;
	
	std::string line;
	while (std::getline(file, line)) {
		result.push(Contact::parse(line));
	}
	return result;
}
