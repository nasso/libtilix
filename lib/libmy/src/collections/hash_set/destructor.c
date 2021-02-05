/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set destructors
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "my/collections/hash_set.h"

static OPT(i32) free_entry_callback(void *user_data, void *raw_element)
{
    hash_set_bucket_element_t *element = raw_element;

    (void)(user_data);
    my_free(element);
    return (NONE(i32));
}

static void destroy_bucket(list_t *bucket)
{
    if (bucket == NULL)
        return;
    list_destroy_with(bucket, &free_entry_callback, NULL);
}

void hash_set_destroy(hash_set_t *self)
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

void hash_set_destroy_with(hash_set_t *self, hash_set_for_each_fn_t *fn,
    void *user_data)
{
    if (self == NULL)
        return;
    if (fn != NULL)
        hash_set_for_each(self, fn, user_data);
    hash_set_destroy(self);
}
