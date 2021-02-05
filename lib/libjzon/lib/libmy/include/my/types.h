/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Primitive typedefs
*/

#ifndef LIBMY_TYPES_H
#define LIBMY_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "my/option.h"
#include "my/result.h"

typedef int fd_t;
typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;
typedef uintptr_t usize_t;
typedef int8_t i8_t;
typedef int16_t i16_t;
typedef int32_t i32_t;
typedef int64_t i64_t;
typedef intptr_t isize_t;
typedef float f32_t;
typedef double f64_t;
OPT_DEFINE(void*, ptr)
OPT_DEFINE(bool, bool)
OPT_DEFINE(char, char)
OPT_DEFINE(u8_t, u8)
OPT_DEFINE(u16_t, u16)
OPT_DEFINE(u32_t, u32)
OPT_DEFINE(u64_t, u64)
OPT_DEFINE(usize_t, usize)
OPT_DEFINE(i8_t, i8)
OPT_DEFINE(i16_t, i16)
OPT_DEFINE(i32_t, i32)
OPT_DEFINE(i64_t, i64)
OPT_DEFINE(isize_t, isize)
OPT_DEFINE(f32_t, f32)
OPT_DEFINE(f64_t, f64)

#include "my/rc.h"
#include "my/sstr.h"

#endif /* LIBMY_TYPES_H */
