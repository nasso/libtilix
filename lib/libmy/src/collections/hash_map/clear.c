/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_clear
*/

#include <stddef.h>
#include "my/mem.h"
#include "my/collections/hash_map.h"
#include "my/collections/list.h"

static OPT(i32) destroy_entry_callback(void *user_data, void *raw_element)
{
    hash_map_bucket_element_t *element = raw_element;

    (void)(user_data);
    my_free((void*) element->pair.key);
    my_free(element);
    return (NONE(i32));
}

void hash_map_clear(hash_map_t *self)
{
    for (usize_t i = 0; i < self->bucket_count; i++)
        if (self->buckets[i]) {
            list_destroy_with(self->buckets[i], &destroy_entry_callback, NULL);
            self->buckets[i] = NULL;
        }
    self->size = 0;
}

void hash_map_clear_with(hash_map_t *self, hash_map_for_each_fn_t *fn,
    void *user_data)
{
    if (fn != NULL)
        hash_map_for_each(self, fn, user_data);
    hash_map_clear(self);
}
