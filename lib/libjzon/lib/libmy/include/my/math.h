/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Maths utils
*/

#ifndef LIBMY_MATH_H
#define LIBMY_MATH_H

#define MY_MAX(A, B) ((A) < (B) ? (B) : (A))
#define MY_MIN(A, B) ((A) > (B) ? (B) : (A))

#include "my/types.h"

#define IMPL_MAX(T) \
    static inline T##_t T##_max(T##_t a, T##_t b) { return (a < b ? b : a); }
#define IMPL_MIN(T) \
    static inline T##_t T##_min(T##_t a, T##_t b) { return (a > b ? b : a); }
#define IMPL_MIN_AND_MAX(T) IMPL_MIN(T) IMPL_MAX(T)

IMPL_MIN_AND_MAX(u8)
IMPL_MIN_AND_MAX(u16)
IMPL_MIN_AND_MAX(u32)
IMPL_MIN_AND_MAX(u64)
IMPL_MIN_AND_MAX(i8)
IMPL_MIN_AND_MAX(i16)
IMPL_MIN_AND_MAX(i32)
IMPL_MIN_AND_MAX(i64)
IMPL_MIN_AND_MAX(f32)
IMPL_MIN_AND_MAX(f64)
IMPL_MIN_AND_MAX(usize)
IMPL_MIN_AND_MAX(isize)

#undef IMPL_MAX
#undef IMPL_MIN
#undef IMPL_MIN_AND_MAX

#endif /* LIBMY_MATH_H */
