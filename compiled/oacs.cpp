#include "oacs.hpp"
namespace acs {
    u0 Str::operator+=(Str value) {
        str a = acs_add(str_, value.str_);
        free(str_);
        str_ = a;
    }
    u0 Str::operator+=(str value) {
        str a = acs_add(str_, value);
        free(str_);
        str_ = a;
    }
    Str Str::substr(i32 s, i32 e) {
        return Str(acs_substr(str_, s, e));
    }
    Spliter Str::get_spliter() {
        return Spliter(str_);
    }
    i32 Str::parse4() {
        return acs_parseint(str_);
    }
    i128 Str::parse16() {
        return acs_big_parseint(str_);
    }
    Str::Str(i32 len) {
        str_ = alloc(i8, len);
    }
    Str::Str(str str__) {
        str_ = str__;
    }
    Str::~Str() {
        free(str_);
    }
    SpliterResult Spliter::split_char(i8 split) {
        SpliterResult r = SpliterResult();
        r.value = acs_spliter_char(spltp, split);
        r.code = (SpliterResultCode)spltp->end;
        return r;
    }
    SpliterResult Spliter::split_str(str split) {
        SpliterResult r = SpliterResult();
        r.value = acs_spliter_string(spltp, split);
        r.code = (SpliterResultCode)spltp->end;
        return r;
    }
    Spliter::Spliter(str str_) {
        spltp = acs_spliter_init(str_);
    }
    Spliter::~Spliter() {
        free(spltp);
    }
}
