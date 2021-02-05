/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vector-like data structure that stores pointers
*/

#ifndef LIBMY_COLLECTIONS_VEC_H
#define LIBMY_COLLECTIONS_VEC_H

#include "my/types.h"

typedef OPT(i32) (vec_iter_fn_t)(void *user_data, void *element);
typedef bool (vec_find_fn_t)(void *user_data, void *element);

typedef struct {
    void **data;
    usize_t len;
    usize_t capacity;
} vec_t;

vec_t *vec_new(void);
vec_t *vec_from(usize_t, ...);
vec_t *vec_from_var(usize_t, va_list);
vec_t *vec_from_arr(usize_t, void**);
vec_t *vec_with_capacity(usize_t);
void vec_destroy(vec_t*);
void vec_destroy_with(vec_t*, vec_iter_fn_t*, void*);
bool vec_reserve(vec_t*, usize_t additional);
bool vec_push(vec_t*, void*);
bool vec_insert(vec_t*, usize_t, void*);
bool vec_add_all(vec_t*, usize_t, ...);
bool vec_add_var(vec_t*, usize_t, va_list);
bool vec_add_arr(vec_t*, usize_t, void**);
bool vec_add_vec(vec_t*, const vec_t*);
OPT(ptr) vec_set(vec_t*, usize_t, void*);
OPT(ptr) vec_pop(vec_t*);
OPT(ptr) vec_remove(vec_t*, usize_t);
OPT(ptr) vec_swap_remove(vec_t*, usize_t);
OPT(ptr) vec_remove_element(vec_t*, void*, vec_find_fn_t*);
void vec_clear(vec_t*);
void vec_clear_with(vec_t*, vec_iter_fn_t*, void*);
OPT(ptr) vec_get(const vec_t*, usize_t);
OPT(ptr) vec_find(vec_t*, void*);
OPT(ptr) vec_find_with(vec_t*, vec_find_fn_t*, void*);
OPT(i32) vec_for_each(vec_t*, vec_iter_fn_t*, void*);

#endif /* LIBMY_COLLECTIONS_VEC_H */
