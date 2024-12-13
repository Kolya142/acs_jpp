#include <acs.hpp>
i32 acs_alog(i32 a, i32 b) {
    i32 i = 0;
    while( a > 0 ){
        a /= b;
        i++;
    }
    return i;
}
i128 acs_big_alog(i128 a, i128 b) {
    i128 i = 0;
    while( a > 0 ){
        a /= b;
        i++;
    }
    return i;
}
str acs_add(str a, str b) {
    i32 la = strlen(a);
    i32 lb = strlen(b);
    str o = alloc(i8, la+lb+1);
    for (i32 i = 0; i < la+lb; i++) {
        if( i < la ){
            o[i] = a[i];
            continue;
        }
        o[i] = b[i - la];
    }
    o[la+lb] = 0;
    return o;
}
str acs_substr(str a, i32 s, i32 e) {
    /*;
       a        start       end;
       |          |          |;
       0  1   2   3  4   5   6;
       ;
       returnurns 3,4,5 from a;
    */
    i32 l = strlen(a);
    if( s < 0 || e >= l ){
        return nil;
    }
    str b = alloc(i8, e-s+1);
    memcpy(b, a+s, e-s);
    b[e-s] = 0;
    return b;
}
u0 acs_creplace(str v, i8 a, i8 b) {
    i32 s = strlen(v);
    for (i32 i = 0; i < s; i++) {
        if( v[i] == a ){
            v[i] = b;
        }
    }
}
str acs_printint(i32 a) {
    U8 n = 0;
    if( a < 0 ){
        n = 1;
        a = -a;
    }
    i32 S = acs_alog(a, 10);
    str s = alloc(i8, S);
    i32 p = 0;
    if( n ){
        s[0] = '-';
        p--;
    }
    while( a > 0 ){
        s[S-1-p] = 0x30 + a % 10;
        a /= 10;
        p++;
    }
    return s;
}
i32 acs_parseint(str a) {
    i32 v = 0;
    i32 i = 0;
    for (;;) {
        if( a[i] == 0 ){
            break;
        }
        if( a[i] >= 0x30 && a[i] <= 0x39 ){
            v *= 10;
            v += a[i] - 0x30;
        }
        i++;
    }
    return v;
}
str acs_big_printint(i128 a) {
    U8 n = 0;
    if( a < 0 ){
        n = 1;
        a = -a;
    }
    i128 S = acs_big_alog(a, 10);
    str s = alloc(i8, S);
    i32 p = 0;
    if( n ){
        s[0] = '-';
        p--;
    }
    while( a > 0 ){
        s[S-1-p] = 0x30 + a % 10;
        a /= 10;
        p++;
    }
    return s;
}
str acs_toobig_printint(u128 a) {
    u128 S = acs_big_alog(a, 10);
    str s = alloc(i8, S);
    i32 p = 0;
    while( a > 0 ){
        s[S-1-p] = 0x30 + a % 10;
        a /= 10;
        p++;
    }
    return s;
}
i128 acs_big_parseint(str a) {
    i128 v = 0;
    i32 i = 0;
    for (;;) {
        if( a[i] == 0 ){
            break;
        }
        if( a[i] >= 0x30 && a[i] <= 0x39 ){
            v *= 10;
            v += a[i] - 0x30;
        }
        i++;
    }
    return v;
}
str acs_cp(str a) {
    int s = strlen(a);
    str o = alloc(i8, s);
    memcpy(o, a, s);
    return o;
}
acs_spliter *acs_spliter_init(str s) {
    acs_spliter *o = alloc(acs_spliter, 1);
    o->s = s;
    o->p = 0;
    o->sz = strlen(s);
    o->end = 0;
    return o;
}
u0 acs_spliter_upd(acs_spliter * self, str s) {
    self->s = s;
    self->p = 0;
    self->sz = strlen(s);
    self->end = 0;
}
u8 acs_spliter_check_result(acs_spliter *self) {
    return self->end;
}
U0 acs_spliter_free(acs_spliter *self) {
    free(self->s);
    free(self);
}
str acs_spliter_char(acs_spliter *self, i8 split) {
    str o = alloc(i8, self->sz);
    memset(o, 0, self->sz);
    i32 i = self->p;
    for (;;) {
        if( i >= self->sz ){
            self->end = 1;
            return acs_milloc(o);
        }
        if( self->s[i] == split ){
            i++;
            break;
        }
        o[i-self->p] = self->s[i];
        i++;
    }
    self->p = i;
    return acs_milloc(o);
}
str acs_spliter_string(acs_spliter *self, str split) {
    str o = alloc(i8, self->sz);
    i32 S = strlen(split);
    memset(o, 0, self->sz);
    i32 i = self->p;
    for (;;) {
        if( i >= self->sz ){
            self->end = 1;
            return acs_milloc(o);
        }
        if( self->s[i] == split[0] ){
            u8 res = 0;
            for (i32 j = 0; j < S; j++) {
                if( i+j > self->sz - 1 || self->s[i+j] != split[j] ){
                    res = 1;
                    break;
                }
            }
            if( !res ){
                i += S;
                break;
            }
        }
        o[i-self->p] = self->s[i];
        i++;
    }
    self->p = i;
    return acs_milloc(o);
}
str acs_milloc(str s) {
    str o = acs_cp(s);
    free(s);
    return o;
}
