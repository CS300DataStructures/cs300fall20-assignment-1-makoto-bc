#include "contact.h"

Contact Contact::parse(const std::string& s) {
	size_t lastSpace = s.find_last_of(' ');

	std::string phoneNumber = s.substr(lastSpace + 1);

	if (lastSpace == std::string::npos) {
		return Contact("", phoneNumber);
	}

	return Contact(s.substr(0, lastSpace), phoneNumber);
}

void Contact::encode(std::string& dst) const {
	dst.clear();
	dst.append(name);
	dst.push_back(' ');
	dst.append(phoneNumber);
}
