#include "contact.h"

Contact Contact::parse(const std::string& s) {
	size_t last_space = s.find_last_of(' ');

	std::string phone_number = s.substr(last_space + 1);
	
	if (last_space == std::string::npos) {
		return Contact("", phone_number);
	}
	
	return Contact(s.substr(0, last_space), phone_number);
}

void Contact::encode(std::string& dst) const {
	dst.clear();
	dst.append(name);
	dst.push_back(' ');
	dst.append(phone_number);
}
