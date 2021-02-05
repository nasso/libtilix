/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Result type
*/

#ifndef LIBMY_RESULT_H
#define LIBMY_RESULT_H

#include <stdbool.h>

#define RES__NOEXPAND(name) my_res__##name##_t
#define RES(name) RES__NOEXPAND(name)
#define RES_ERR(name, ...) my_res__##name##_err(__VA_ARGS__)
#define RES_OK(name, ...) my_res__##name##_ok(__VA_ARGS__)
#define RES_DEFINE(T, E, name) \
\
typedef struct { \
    bool is_ok; \
    union { \
        T ok; \
        E err; \
    } u; \
} RES(name); \
\
static inline RES(name) my_res__##name##_ok(T val) \
{ \
    return ((RES(name)) { .is_ok = true, .u.ok = val }); \
} \
\
static inline RES(name) my_res__##name##_err(E val) \
{ \
    return ((RES(name)) { .is_ok = false, .u.err = val }); \
}

#endif /* LIBMY_RESULT_H */
