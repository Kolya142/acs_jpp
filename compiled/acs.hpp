#define jppt
#define pi(I) printf("%d", I)
#define px(I) printf("%02X", I)
#define pf printf

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif
#define i8 char
#define i16 int16_t
#define i32 int
#define i64 long long
#define i128 __int128_t
#define u0 void
#define u8 unsigned char
#define u16 uint16_t
#define u32 unsigned int
#define u64 unsigned long long
#define u128 __uint128_t
#define I8 i8
#define I16 i16
#define I32 i32
#define I64 i64
#define I128 i128
#define U0 u0
#define U8 u8
#define U16 u16
#define U32 u32
#define U64 u64
#define U128 u128
#define nil NULL
#define str i8*
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