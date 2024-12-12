#include "jpp_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#pragma once

i32 acs_alog(i32 a, i32 b);
i128 acs_big_alog(i128 a, i128 b);

str acs_add(str a, str b);
str acs_substr(str a, i32 start, i32 end);
u0 acs_creplace(str v, i8 a, i8 b);
str acs_printint(i32 a);
int acs_parseint(str a);
str acs_big_printint(i128 a);
str acs_toobig_printint(u128 a);
i128 acs_big_parseint(str a);
str acs_cp(str a);
struct acs_spliter {
    str s;
    i32 sz;
    i32 p;
    i32 end;
};
acs_spliter *acs_spliter_init(str s);
u0 acs_spliter_upd(acs_spliter *self, str s);
u8 acs_spliter_check_result(acs_spliter *self);
u0 acs_spliter_free(acs_spliter *self);
str acs_spliter_char(acs_spliter *self, i8 split);
str acs_spliter_string(acs_spliter *self, str split);
str acs_milloc(str s);