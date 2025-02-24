#include <fstream>
#include <cstring>
#include "file.h"

namespace file {

ContactList open(const std::string& path) {
	std::ifstream file(path);
	return ContactList::parse(file);
}

void replace(const std::string& path, const ContactList& list) {
	std::remove((path + ".tmp").c_str());

	{
		std::ofstream file(path + ".tmp");
		if (file.fail()) {
			throw std::runtime_error(std::strerror(errno));
		}

		list.encode(file);
		if (file.fail()) {
			throw std::runtime_error(std::strerror(errno));
		}
	}

	std::remove(path.c_str());

	std::rename((path + ".tmp").c_str(), path.c_str());
}

}