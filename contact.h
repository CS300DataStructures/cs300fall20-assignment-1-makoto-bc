#ifndef ASSIGNMENT_1__CONTACT_H_
#define ASSIGNMENT_1__CONTACT_H_

#include <string>
#include <utility>
#include <tuple>

/**
 * Contains a name and a phone number.
 */
class Contact {
public:
	std::string name;
	std::string phone_number;
	
	Contact(std::string name, std::string phone_number)
		: name(std::move(name))
		, phone_number(std::move(phone_number))
	{}
	
	/**
	 * Parses given string.
	 */
	static Contact parse(const std::string& s);

	/**
	 * Encodes this contact and writes it to dst. dst is cleared prior to writing.
	 */
	void encode(std::string& dst) const;
	
	bool operator==(const Contact &rhs) const {
		return std::tie(name, phone_number) == std::tie(rhs.name, rhs.phone_number);
	}
};

#endif //ASSIGNMENT_1__CONTACT_H_
