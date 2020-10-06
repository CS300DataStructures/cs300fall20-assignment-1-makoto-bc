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
Contact input_contact() {
	std::string name;
	std::cout << "Enter name: " << std::flush;
	std::getline(std::cin, name);

	std::string phone_number;
	while (true) {
		std::cout << "Enter phone: " << std::flush;
		std::getline(std::cin, phone_number);
		// A space in the phone number will change the name when decoded
		if (std::count(phone_number.cbegin(), phone_number.cend(), ' ') == 0) {
			break;
		} else {
			std::cout << "Phone is invalid.\n";
		}
	}
	return Contact(name, phone_number);
}

const char* phonebook_path = "phonebook.txt";

int main() {
	ContactList list = file::open(phonebook_path);
	
	std::cout << "***MY PHONEBOOK APPLICATION***\nPlease choose an operation:\n";

	while(true) {
		std::cout << "A(Add) | S (Search) | D(Delete) | L(List) | Q(Quit): " << std::flush;
		
		std::string input;
		std::getline(std::cin, input);
		
		if (input.size() != 1) {
			std::cout << "Invalid option.\n\n";
			continue;
		}
		
		switch (input[0]) {
		case Command::add: {
			list.push(input_contact());
			file::replace(phonebook_path, list);
			std::cout << "Contact added.";
			break;
		}
		case Command::search: {
			if (list.exists(input_contact())) {
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
			
			size_t original_size = list.size();
			list.delete_(name);
			file::replace(phonebook_path, list);
			std::cout << original_size - list.size() << " record(s) deleted.";
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