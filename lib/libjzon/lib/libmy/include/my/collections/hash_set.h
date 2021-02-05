/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Hash set data structure
*/

#ifndef LIBMY_COLLECTIONS_HASH_SET_H
#define LIBMY_COLLECTIONS_HASH_SET_H

#include <stdarg.h>
#include <stdbool.h>
#include "my/types.h"
#include "my/collections/list.h"

typedef struct {
    const u64_t hash;
    void *value;
} hash_set_bucket_element_t;

typedef OPT(i32) (hash_set_for_each_fn_t)(void *user_data, void *value);
typedef u64_t (hash_set_hash_fn_t)(const void*);
typedef bool (hash_set_eq_fn_t)(const void*, const void*);

typedef struct {
    hash_set_hash_fn_t *fn;
    hash_set_eq_fn_t *eq;
    usize_t size;
    usize_t bucket_count;
    list_t **buckets;
} hash_set_t;

hash_set_t *hash_set_new(hash_set_hash_fn_t*);
hash_set_t *hash_set_with_eq(hash_set_hash_fn_t*, hash_set_eq_fn_t*);
hash_set_t *hash_set_with_buckets(hash_set_hash_fn_t*, usize_t);
hash_set_t *hash_set_with_eq_and_buckets(hash_set_hash_fn_t*,
    hash_set_eq_fn_t*, usize_t);
hash_set_t *hash_set_from(hash_set_hash_fn_t*, usize_t, ...);
hash_set_t *hash_set_from_var(hash_set_hash_fn_t*, usize_t, va_list);
hash_set_t *hash_set_from_arr(hash_set_hash_fn_t*, usize_t, void *const *arr);
hash_set_t *hash_set_clone(const hash_set_t*);
hash_set_t *hash_set_clone_with(const hash_set_t*, void *(*clone)(const void*),
    void (*destroy)(void*));
void hash_set_destroy(hash_set_t*);
void hash_set_destroy_with(hash_set_t*, hash_set_for_each_fn_t*, void*);
bool hash_set_insert(hash_set_t*, void*);
bool hash_set_insert_all(hash_set_t*, usize_t, ...);
bool hash_set_insert_all_var(hash_set_t*, usize_t, va_list);
bool hash_set_insert_all_arr(hash_set_t *self, usize_t n, void *const *arr);
const void *hash_set_remove(hash_set_t*, const void*);
void hash_set_clear(hash_set_t*);
void hash_set_clear_with(hash_set_t*, hash_set_for_each_fn_t*, void*);
bool hash_set_has(const hash_set_t*, const void*);
OPT(i32) hash_set_for_each(hash_set_t*, hash_set_for_each_fn_t*, void*);

#endif /* LIBMY_COLLECTIONS_HASH_SET_H */
