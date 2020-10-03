#include "contact.h"

Contact Contact::parse(const std::string &row) {
	size_t first_space = row.find(' ');
	size_t second_space = row.find(' ', first_space + 1);

	std::string name = row.substr(0, second_space);
	
	if (second_space == std::string::npos) {
		return Contact(name, "");
	}
	
	return Contact(name, row.substr(second_space + 1));
}
