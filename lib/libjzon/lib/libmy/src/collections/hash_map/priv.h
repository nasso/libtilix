/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** private hash_map functions
*/

#ifndef LIBMY_COLLECTIONS_HASH_MAP_PRIV_H
#define LIBMY_COLLECTIONS_HASH_MAP_PRIV_H

#include <stdbool.h>
#include "my/types.h"
#include "my/collections/hash_map.h"
#include "my/collections/list.h"

bool hash_map__grow(hash_map_t*, usize_t);
bool hash_map__insert_entry(hash_map_t*, const hash_map_bucket_element_t*);
void hash_map__refresh_stats(hash_map_t*);
hash_map_bucket_element_t *hash_map__bucket_element_new(u64_t, const char*);
void hash_map__bucket_element_destroy(hash_map_bucket_element_t*);

#endif /* LIBMY_COLLECTIONS_HASH_MAP_PRIV_H */
