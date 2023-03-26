#pragma once
#include <hooker/hook.h>

// std::string::string(const char *c_str)
struct string *cpp_string__string(const char *c_str);

// std::string::c_str()
const char *cpp_string__c_str(struct string *cpp_str);
