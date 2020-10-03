#include <fstream>
#include <cstring>
#include "contact_list.h"

int main() {
	ContactList contact_list({});
	{
		std::ifstream file("phonebook.txt");
		if (file.fail()) {
			std::cerr << std::strerror(errno);
			return 1;
		}
		contact_list = ContactList::parse(file);
	}
}