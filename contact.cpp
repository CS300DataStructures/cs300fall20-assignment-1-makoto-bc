#include "contact.h"

Contact Contact::parse(const std::string& s) {
	size_t first_space = s.find(' ');
	size_t second_space = s.find(' ', first_space + 1);

	std::string name = s.substr(0, second_space);
	
	if (second_space == std::string::npos) {
		return Contact(name, "");
	}
	
	return Contact(name, s.substr(second_space + 1));
}

void Contact::encode(std::string& dst) const {
	dst.clear();
	dst.append(name);
	dst.push_back(' ');
	dst.append(phone_number);
}
