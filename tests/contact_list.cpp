#include <gtest/gtest.h>
#include "../contact_list.h"

TEST(ContactList, parse) {
	struct Test {
		const std::string file;
		const ContactList expected;
	};
	
	std::vector<Test> tests {
		{
			"",
			ContactList(),
		},
		{
			"a b c\n",
			ContactList({Contact("a b", "c")}),
		},
		{
			"a b c\na b c",
			ContactList({
				Contact("a b", "c"),
				Contact("a b", "c"),
			}),
		},
	};
	
	for (size_t i = 0; i < tests.size(); ++i) {
		std::istringstream stream(tests[i].file);
		ContactList result = ContactList::parse(stream);
		EXPECT_EQ(result, tests[i].expected) << i;
	}
}
