#include "contact_list.h"

ContactList ContactList::parse(std::istream& file) {
	ContactList result({});
	
	std::string line;
	while (std::getline(file, line, '\n')) {
		if (line[line.size() - 1] == '\r') {
			line.pop_back();
		}
		result.push(Contact::parse(line));
	}
	
	file.clear();
	return result;
}

void ContactList::encode(std::ostream& file) const {
	std::string buf;
	for (size_t i = 0; i < _list.size(); ++i) {
		_list[i].encode(buf);
		file << buf;
		if (i < _list.size() - 1) {
			file << "\r\n";
		}
	}
}
