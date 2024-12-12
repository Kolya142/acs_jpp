// object amazing c strings library
#include "acs.hpp"
#pragma once
namespace acs {
    enum SpliterResultCode {
        SUCCESS = 0,
        END_OF_STR = 1
    };
    struct SpliterResult {
        str value;
        SpliterResultCode code;
    };
    struct Spliter {
        acs_spliter *spltp;
        SpliterResult split_char(i8 split);
        SpliterResult split_str(str split);
        Spliter(str str_);
        ~Spliter();
    };
    struct Str {
        str str_;
        u0 operator+=(Str value);
        u0 operator+=(str value);
        Str substr(i32 s, i32 e);
        Spliter get_spliter();
        i32 parse4();
        i128 parse16();
        Str(i32 len);
        Str(str str__);
        ~Str();
    };
}