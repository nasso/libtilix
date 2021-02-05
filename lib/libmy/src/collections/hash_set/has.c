/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set_has
*/

#include "my/my.h"
#include "my/collections/hash_set.h"
#include "my/collections/list.h"

bool hash_set_has(const hash_set_t *self, const void *value)
{
    u64_t hash = self->fn(value);
    list_t *bucket = self->buckets[hash % self->bucket_count];
    hash_set_bucket_element_t *elem = NULL;

    if (bucket == NULL)
        return (false);
    LIST_FOR_EACH(bucket, iter) {
        elem = iter.v;
        if (self->eq == NULL ? (value == iter.v) : self->eq(value, elem->value))
            return (true);
    }
    return (false);
}
