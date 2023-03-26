#include <example/cpp_string.h>

// std::string::string(const char *c_str)
struct string *cpp_string__string(const char *c_str)
{
    size_t extra_len = 32;
    struct string *cpp_str = malloc(strlen(c_str) + extra_len);
    TMCALL("??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@QEBD@Z",
        const char *(*)(struct string *cpp_str, const char *c_str),
        cpp_str, c_str);
    return cpp_str;
}

// std::string::c_str()
const char *cpp_string__c_str(struct string *cpp_str)
{
    const char *c_str = 
        TMCALL("?c_str@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBAPEBDXZ",
            const char *(*)(struct string *cpp_str),
            cpp_str);
    return c_str;
}
