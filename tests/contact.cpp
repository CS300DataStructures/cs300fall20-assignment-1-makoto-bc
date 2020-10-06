#include <gtest/gtest.h>
#include "../contact.h"

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
	return os << "{" << contact.name << ", " << contact.phone_number << "}";
}

TEST(Contact, parse) {
	struct Test {
		const std::string row;
		const Contact expected;
	};
	
	std::vector<Test> tests {
		{
			"",
			{"", ""},
		},
		{
			"a",
			{"", "a"},
		},
		{
			" a",
			{"", "a"},
		},
		{
			"a ",
			{"a", ""},
		},
		{
			"a b",
			{"a", "b"},
		},
		{
			"a b c",
			{"a b", "c"},
		},
	};
	
	for (size_t i = 0; i < tests.size(); ++i) {
		EXPECT_EQ(Contact::parse(tests[i].row), tests[i].expected) << i;
	}
}

TEST(Contact, encode) {
	std::string result;
	Contact("name", "phone").encode(result);
	EXPECT_EQ(result, "name phone");
}