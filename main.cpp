#include <fstream>
#include <cstring>
#include "contact_list.h"

int main() {
	std::ifstream file("phonebook.txt");
	if (file.fail()) {
		std::cerr << std::strerror(errno);
		return 1;
	}
	auto _ = ContactList::parse(file);
}