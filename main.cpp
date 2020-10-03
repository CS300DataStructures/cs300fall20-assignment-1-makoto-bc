#include "file.h"

int main() {
	auto list = file::open("phonebook.txt");
	list.push(Contact("test", "test"));
	file::replace("phonebook.txt", list);
}