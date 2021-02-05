/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Hash map data structure
*/

#ifndef LIBMY_COLLECTIONS_HASH_MAP_H
#define LIBMY_COLLECTIONS_HASH_MAP_H

#include <stdarg.h>
#include <stdbool.h>
#include "my/types.h"
#include "my/collections/list.h"

RES_DEFINE(OPT(ptr), bool, hash_map_insert)

typedef struct {
    const char *const key;
    void *value;
} hash_map_pair_t;

typedef struct {
    const u64_t hash;
    hash_map_pair_t pair;
} hash_map_bucket_element_t;

typedef OPT(i32) (hash_map_for_each_fn_t)(void *user_data,
    hash_map_pair_t *pair);
typedef u64_t (hash_map_hasher_fn_t)(const char*);

typedef struct {
    hash_map_hasher_fn_t *const fn;
    usize_t size;
    usize_t bucket_count;
    list_t **buckets;
} hash_map_t;

hash_map_t *hash_map_new(void);
hash_map_t *hash_map_with_hasher(hash_map_hasher_fn_t*);
hash_map_t *hash_map_with_hasher_and_buckets(hash_map_hasher_fn_t*, usize_t);
hash_map_t *hash_map_from(usize_t, ...);
hash_map_t *hash_map_from_var(usize_t, va_list);
hash_map_t *hash_map_from_arr(usize_t, hash_map_pair_t*);
hash_map_t *hash_map_clone(const hash_map_t*);
hash_map_t *hash_map_clone_with(const hash_map_t*, void *(*)(void*),
    void (*)(void*));
void hash_map_destroy(hash_map_t*);
void hash_map_destroy_with(hash_map_t*, hash_map_for_each_fn_t*, void*);
RES(hash_map_insert) hash_map_insert(hash_map_t*, const char*, void*);
bool hash_map_insert_all(hash_map_t*, usize_t, ...);
bool hash_map_insert_all_var(hash_map_t*, usize_t, va_list);
bool hash_map_insert_all_arr(hash_map_t*, usize_t, hash_map_pair_t*);
OPT(ptr) hash_map_remove(hash_map_t*, const char*);
void hash_map_clear(hash_map_t*);
void hash_map_clear_with(hash_map_t*, hash_map_for_each_fn_t*, void*);
OPT(ptr) hash_map_get(const hash_map_t*, const char*);
OPT(i32) hash_map_for_each(hash_map_t*, hash_map_for_each_fn_t*, void*);
bool hash_map_contains_key(const hash_map_t*, const char*);

#endif /* LIBMY_COLLECTIONS_HASH_MAP_H */
