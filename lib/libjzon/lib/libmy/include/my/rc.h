/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** reference counting (shared pointers)
*/

#ifndef LIBMY_RC_H
#define LIBMY_RC_H

#include "my/types.h"
#include "my/mem.h"

#define RC_TYPE(name) struct my_rc__##name
#define WRC_TYPE(name) struct my_wrc__##name
#define RC(name) RC_TYPE(name) *
#define WRC(name) WRC_TYPE(name) *
#define RC_NEW(name) my_rc__##name##_new
#define RC_WRAP(name) my_rc__##name##_wrap
#define RC_INC(name) my_rc__##name##_inc
#define RC_DROP(name) my_rc__##name##_dec
#define RC_WEAK(name) my_rc__##name##_weak
#define WRC_DROP(name) my_wrc__##name##_drop
#define WRC_ALIVE(name) my_wrc__##name##_alive
#define RC_DEFINE(type, name, free_cb) \
\
RC_TYPE(name) { \
    type *v; \
    usize_t strong; \
    usize_t weak; \
}; \
\
WRC_TYPE(name) { \
    RC(name) ptr; \
}; \
\
static inline RC(name) RC_NEW(name)(void) { \
    RC(name) ptr = my_calloc(1, sizeof(RC_TYPE(name))); \
    \
    if (ptr == NULL) \
        return (NULL); \
    ptr->strong++; \
    return (ptr); \
} \
\
static inline RC(name) RC_WRAP(name)(type *v) { \
    RC(name) ptr = NULL; \
    \
    if (v == NULL) \
        return (NULL); \
    ptr = RC_NEW(name)(); \
    if (ptr == NULL) { \
        if (free_cb != NULL) \
            free_cb(v); \
        return (NULL); \
    } \
    ptr->v = v; \
    return (ptr); \
} \
\
static inline RC(name) RC_INC(name)(RC(name) ptr) { \
    ptr->strong++; \
    return (ptr); \
} \
\
static inline void RC_DROP(name)(RC(name) ptr) { \
    if (ptr->strong == 0) \
        return; \
    ptr->strong--; \
    if (ptr->strong == 0) { \
        if (free_cb != NULL) \
            free_cb(ptr->v); \
        if (ptr->weak == 0) \
            my_free(ptr); \
    } \
} \
\
static inline WRC(name) RC_WEAK(name)(RC(name) ptr) { \
    WRC(name) weak = my_calloc(1, sizeof(WRC_TYPE(name))); \
    \
    if (weak == NULL) \
        return (NULL); \
    weak->ptr = ptr; \
    weak->ptr->weak++; \
    return (weak); \
} \
\
static inline void WRC_DROP(name)(WRC(name) ptr) { \
    if (ptr == NULL) \
        return; \
    ptr->ptr->weak--; \
    if (ptr->ptr->weak == 0 && ptr->ptr->strong == 0) \
        my_free(ptr->ptr); \
    my_free(ptr); \
} \
\
static inline bool WRC_ALIVE(name)(WRC(name) ptr) { \
    if (ptr == NULL) \
        return (false); \
    return (ptr->ptr->strong != 0); \
} \

#endif /* LIBMY_RC_H */
