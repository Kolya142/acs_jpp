#ifndef jppt
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
#define ret return
#define alloc(T, S) (T*)malloc(sizeof(T)*S)
#define pbegin Nabs::PFunc profiler_wrap = Nabs::PBegin(__FILE__, __FUNCTION__, __LINE__)
#define pend Nabs::PEnd(profiler_wrap)
#define ppbegin Nabs::PClear()
#define str i8*
#endif
#include "oacs.hpp"
#
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
        ret Str(acs_substr(str_, s, e));
    }
    Spliter Str::get_spliter() {
        ret Spliter(str_);
    }
    i32 Str::parse4() {
        ret acs_parseint(str_);
    }
    i128 Str::parse16() {
        ret acs_big_parseint(str_);
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
        ret r;
    }
    SpliterResult Spliter::split_str(str split) {
        SpliterResult r = SpliterResult();
        r.value = acs_spliter_string(spltp, split);
        r.code = (SpliterResultCode)spltp->end;
        ret r;
    }
    Spliter::Spliter(str str_) {
        spltp = acs_spliter_init(str_);
    }
    Spliter::~Spliter() {
        free(spltp);
    }
}
