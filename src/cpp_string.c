#include <example/cpp_string.h>

// std::string::c_str()
const char *cpp_string__c_str(struct string *cpp_str)
{
    const char *c_str = 
        TMCALL("?c_str@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBAPEBDXZ",
            const char *(*)(struct string *cpp_str),
            cpp_str);
    return c_str;
}
