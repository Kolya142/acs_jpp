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
#include <stdio.h>
#include <stdlib.h>
#
#include "oacs.hpp"
#
i32 main() {
str text = "hello, world, and, jpp";

acs::Spliter spltr = acs::Spliter(text);

pf("spliting %s for ', '\n", text);
str a = spltr.split_str(", ").value;
pf("first: %s\n", a);
free(a);



ret 0; 
}