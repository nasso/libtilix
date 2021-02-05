/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set__bucket_element_*
*/

#include "my/my.h"
#include "my/collections/hash_set.h"
#include "../priv.h"

hash_set_bucket_element_t *hash_set__bucket_element_new(u64_t hash,
    void *value)
{
    hash_set_bucket_element_t init = { .hash = hash, .value = value };
    hash_set_bucket_element_t *elem = NULL;

    elem = my_malloc(sizeof(hash_set_bucket_element_t));
    if (elem == NULL)
        return (NULL);
    my_memcpy(elem, &init, sizeof(hash_set_bucket_element_t));
    return (elem);
}

void hash_set__bucket_element_destroy(hash_set_bucket_element_t *self)
{
    if (self == NULL)
        return;
    my_free(self);
}
