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
			ContactList({}),
		},
		{
			"a b c\r\n",
			ContactList({Contact("a b", "c")}),
		},
		{
			"a b c\r\na b c",
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

TEST(ContactList, encode) {
	{
		std::stringstream result;
		ContactList({}).encode(result);
		EXPECT_EQ(result.str(), "");
	}
	{
		std::stringstream result;
		ContactList({{"a", "b"}, {"c", "d"}}).encode(result);
		EXPECT_EQ(result.str(), "a b\nc d");
	}
}

TEST(ContactList, exists) {
	bool result = ContactList({}).exists(Contact("", ""));
	EXPECT_EQ(result, false);

	result = ContactList({{"", ""}}).exists(Contact("", ""));
	EXPECT_EQ(result, true);
}

TEST(ContactList, delete_) {
	{
		ContactList list({});
		list.delete_("");
		EXPECT_EQ(list, ContactList({}));
	}
	{
		ContactList list({{"", ""}, {"", "a"}, {"b", "c"}});
		list.delete_("");
		EXPECT_EQ(list, ContactList({{"b", "c"}}));
	}
}