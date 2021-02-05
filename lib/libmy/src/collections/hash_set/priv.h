/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** private hash_set functions
*/

#ifndef LIBMY_COLLECTIONS_HASH_MAP_PRIV_H
#define LIBMY_COLLECTIONS_HASH_MAP_PRIV_H

#include <stdbool.h>
#include "my/types.h"
#include "my/collections/hash_set.h"
#include "my/collections/list.h"

bool hash_set__grow(hash_set_t *self, usize_t new_size);
bool hash_set__insert_entry(hash_set_t *self, const hash_set_bucket_element_t*);
void hash_set__refresh_stats(hash_set_t *self);
hash_set_bucket_element_t *hash_set__bucket_element_new(u64_t hash,
    void *value);
void hash_set__bucket_element_destroy(hash_set_bucket_element_t*);

#endif /* LIBMY_COLLECTIONS_HASH_MAP_PRIV_H */
