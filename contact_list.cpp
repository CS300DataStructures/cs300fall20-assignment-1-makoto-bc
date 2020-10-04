#include <optional>
#include "contact_list.h"
#include <algorithm>

ContactList ContactList::parse(std::istream& file) {
	ContactList result({});
	
	std::string line;
	while (std::getline(file, line)) {
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
			file << "\n";
		}
	}
}

void ContactList::output(std::ostream& out) const {
	std::string buf;
	for (size_t i = 0; i < _list.size(); ++i) {
		_list[i].encode(buf);
		out << buf;
		if (i < _list.size() - 1) {
			out << "\n";
		}
	}
}

bool ContactList::exists(const Contact& contact) const {
	return std::find(_list.cbegin(), _list.cend(), contact) != _list.cend();
}

void ContactList::delete_(const std::string& contact_name) {
	auto pred = [&](const Contact& c){
		return c.name == contact_name;
	};
	_list.erase(std::remove_if(_list.begin(), _list.end(), pred), _list.end());
}