#include "contact_list.h"

ContactList ContactList::parse(std::istream& file) {
	ContactList result;
	
	std::string line;
	while (std::getline(file, line, '\n')) {
		if (line[line.size() - 1] == '\r') {
			line.pop_back();
		}
		result.push(Contact::parse(line));
	}
	
	file.clear(); // getline() annoyingly sets failbit every time
	return result;
}
