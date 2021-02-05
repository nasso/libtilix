/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map__bucket_element_*
*/

#include "my/my.h"
#include "my/cstr.h"
#include "my/collections/hash_map.h"
#include "../priv.h"

hash_map_bucket_element_t *hash_map__bucket_element_new(u64_t hash,
    const char *key)
{
    hash_map_bucket_element_t init = {hash, {my_cstrdup(key), NULL}};
    hash_map_bucket_element_t *elem = NULL;

    elem = my_malloc(sizeof(hash_map_bucket_element_t));
    if (elem == NULL || init.pair.key == NULL) {
        my_free(elem);
        my_free((void*) init.pair.key);
        return (NULL);
    }
    my_memcpy(elem, &init, sizeof(hash_map_bucket_element_t));
    return (elem);
}

void hash_map__bucket_element_destroy(hash_map_bucket_element_t *self)
{
    if (self == NULL)
        return;
    my_free((void*) self->pair.key);
    my_free(self);
}
