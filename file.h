#ifndef ASSIGNMENT_1__FILE_H_
#define ASSIGNMENT_1__FILE_H_

#include "contact_list.h"

namespace file {

/**
 * Parses phonebook file.
 * @param path Phonebook filepath 
 * @return The parsed ContactList
 */
ContactList open(const std::string& path);

/**
 * Safely writes list to given path.
 * @param path Phonebook filepath 
 * @param list The new ContactList to save to file
 */
void replace(const std::string& path, const ContactList& list);

}

#endif //ASSIGNMENT_1__FILE_H_
