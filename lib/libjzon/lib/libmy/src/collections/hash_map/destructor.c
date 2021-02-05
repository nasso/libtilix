/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map destructors
*/

#include <stddef.h>
#include "my/my.h"
#include "my/collections/list.h"
#include "my/collections/hash_map.h"

static OPT(i32) free_entry_callback(void *user_data, void *raw_element)
{
    hash_map_bucket_element_t *element = raw_element;

    (void)(user_data);
    my_free((void*) element->pair.key);
    my_free(element);
    return (NONE(i32));
}

static void destroy_bucket(list_t *bucket)
{
    if (bucket == NULL)
        return;
    list_destroy_with(bucket, &free_entry_callback, NULL);
}

void hash_map_destroy(hash_map_t *self)
{
    if (self == NULL)
        return;
    if (self->buckets) {
        for (usize_t i = 0; i < self->bucket_count; i++)
            destroy_bucket(self->buckets[i]);
        my_free(self->buckets);
    }
    my_free(self);
}

void hash_map_destroy_with(hash_map_t *self, hash_map_for_each_fn_t *fn,
    void *user_data)
{
    if (self == NULL)
        return;
    if (fn != NULL)
        hash_map_for_each(self, fn, user_data);
    hash_map_destroy(self);
}
