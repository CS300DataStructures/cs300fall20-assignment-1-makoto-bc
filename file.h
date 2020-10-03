#ifndef ASSIGNMENT_1__FILE_H_
#define ASSIGNMENT_1__FILE_H_

#include "contact_list.h"

namespace file {

ContactList open(const std::string& path);

void replace(const std::string& path, const ContactList& list);

}

#endif //ASSIGNMENT_1__FILE_H_
