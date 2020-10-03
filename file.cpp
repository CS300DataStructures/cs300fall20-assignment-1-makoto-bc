#include <fstream>
#include <cstring>
#include "file.h"

namespace file {

ContactList open(const std::string& path) {
	std::ifstream file(path);
	if (file.fail()) {
		throw std::runtime_error(std::strerror(errno));
	}
	return ContactList::parse(file);
}

void replace(const std::string& path, const ContactList& list) {
	{
		std::ofstream file(path + ".tmp");
		if (file.fail()) {
			throw std::runtime_error(std::strerror(errno));
		}

		list.encode(file);
	}

	std::remove(path.c_str());

	std::rename((path + ".tmp").c_str(), path.c_str());
}

}