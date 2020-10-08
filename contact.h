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
	std::string phoneNumber;

	Contact(std::string name, std::string phoneNumber)
		: name(std::move(name))
		  , phoneNumber(std::move(phoneNumber)) {}

	/**
	 * Parses given string.
	 */
	static Contact parse(const std::string& s);

	/**
	 * Encodes this contact and writes it to dst. dst is cleared prior to writing.
	 */
	void encode(std::string& dst) const;

	bool operator==(const Contact& rhs) const {
		return std::tie(name, phoneNumber) == std::tie(rhs.name, rhs.phoneNumber);
	}
};

#endif //ASSIGNMENT_1__CONTACT_H_
