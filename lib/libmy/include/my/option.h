/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Option type
*/

#ifndef LIBMY_OPTION_H
#define LIBMY_OPTION_H

#include <stdbool.h>

#define OPT__NOEXPAND(name) my_opt__##name##_t
#define OPT(name) OPT__NOEXPAND(name)
#define SOME(name, ...) my_opt__##name##_some(__VA_ARGS__)
#define NONE(name) my_opt__##name##_none()
#define OPT_TYPEOF(name) my_opt__##name##_type_t
#define OPT_DEFINE(T, name) \
\
typedef T OPT_TYPEOF(name); \
\
typedef struct { \
    bool is_some; \
    OPT_TYPEOF(name) v; \
} OPT(name); \
\
static inline OPT(name) my_opt__##name##_none(void) \
{ \
    return ((OPT(name)) { .is_some = false }); \
} \
\
static inline OPT(name) my_opt__##name##_some(OPT_TYPEOF(name) val) \
{ \
    return ((OPT(name)) { .is_some = true, .v = val }); \
}

#endif /* LIBMY_OPTION_H */
