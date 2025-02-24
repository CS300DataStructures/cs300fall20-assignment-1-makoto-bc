// Assignment-1
// Makoto Emura
// 10/8/2020
// Description: Displays an interface for managing a phonebook and 
// stores this information in phonebook.txt

#include <algorithm>
#include "file.h"

enum Command {
	add = 'A',
	search = 'S',
	delete_ = 'D',
	list = 'L',
	quit = 'Q',
};

/**
 * Asks for contact info.
 */
Contact inputContact() {
	std::string name;
	std::cout << "Enter name: " << std::flush;
	std::getline(std::cin, name);

	std::string phoneNumber;
	while (true) {
		std::cout << "Enter phone: " << std::flush;
		std::getline(std::cin, phoneNumber);
		// A space in the phone number will change the name when decoded
		if (std::count(phoneNumber.cbegin(), phoneNumber.cend(), ' ') == 0) {
			break;
		} else {
			std::cout << "Phone is invalid.\n";
		}
	}
	return Contact(name, phoneNumber);
}

int main() {
	const std::string phonebookPath = "phonebook.txt";
	ContactList list = file::open(phonebookPath);

	std::cout << "***MY PHONEBOOK APPLICATION***\nPlease choose an operation:\n";

	while (true) {
		std::cout << "A(Add) | S (Search) | D(Delete) | L(List) | Q(Quit): " << std::flush;

		std::string input;
		std::getline(std::cin, input);

		if (input.size() != 1) {
			std::cout << "Invalid option.\n\n";
			continue;
		}

		switch (input[0]) {
		case Command::add: {
			list.push(inputContact());
			file::replace(phonebookPath, list);
			std::cout << "Contact added.";
			break;
		}
		case Command::search: {
			if (list.exists(inputContact())) {
				std::cout << "This contact exists.";
			} else {
				std::cout << "This contact does not exist.";
			}
			break;
		}
		case Command::delete_: {
			std::cout << "Enter name: " << std::flush;
			std::string name;
			std::getline(std::cin, name);

			size_t originalSize = list.size();
			list.delete_(name);
			file::replace(phonebookPath, list);
			std::cout << originalSize - list.size() << " record(s) deleted.";
			break;
		}
		case Command::list: {
			list.output(std::cout);
			break;
		}
		case Command::quit: {
			std::exit(EXIT_SUCCESS);
		}
		default: {
			std::cout << "Invalid option.";
		}
		}

		std::cout << "\n\n";
	}
}