#ifndef ASSIGNMENT_1__CONTACT_H_
#define ASSIGNMENT_1__CONTACT_H_

#include <string>
#include <utility>
#include <tuple>

class Contact {
public:
	Contact(std::string name, std::string phone_number)
		: _name(std::move(name))
		, _phone_number(std::move(phone_number))
	{}
	
	static Contact parse(const std::string& row);
	
	const std::string& name() const {
		return _name;
	}
	
	const std::string& phone_number() const {
		return _phone_number;
	}

	void encode(std::string& dst) const;
	
	bool operator==(const Contact &rhs) const {
		return std::tie(_name, _phone_number) == std::tie(rhs._name, rhs._phone_number);
	}
	
private:
	std::string _name;
	std::string _phone_number;
};

#endif //ASSIGNMENT_1__CONTACT_H_
