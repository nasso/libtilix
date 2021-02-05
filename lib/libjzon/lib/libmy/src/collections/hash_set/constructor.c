/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set constructors
*/

#include "my/mem.h"
#include "my/hash.h"
#include "my/collections/hash_set.h"

hash_set_t *hash_set_new(hash_set_hash_fn_t *hasher)
{
    return (hash_set_with_eq_and_buckets(hasher, NULL, 32));
}

hash_set_t *hash_set_with_eq(hash_set_hash_fn_t *hasher, hash_set_eq_fn_t *eq)
{
    return (hash_set_with_eq_and_buckets(hasher, eq, 32));
}

hash_set_t *hash_set_with_buckets(hash_set_hash_fn_t *hasher,
    usize_t bucket_count)
{
    return (hash_set_with_eq_and_buckets(hasher, NULL, bucket_count));
}

hash_set_t *hash_set_with_eq_and_buckets(hash_set_hash_fn_t *hasher,
    hash_set_eq_fn_t *eq, usize_t bucket_count)
{
    hash_set_t init = {.fn = hasher, .eq = eq, .bucket_count = bucket_count};
    hash_set_t *self = my_malloc(sizeof(hash_set_t));

    if (self == NULL)
        return (NULL);
    my_memcpy(self, &init, sizeof(hash_set_t));
    self->buckets = my_calloc(self->bucket_count, sizeof(list_t*));
    if (self->buckets == NULL) {
        my_free(self);
        return (NULL);
    }
    return (self);
}
