/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_for_each
*/

#include "my/my.h"
#include "my/collections/hash_map.h"

struct for_each_opts {
    hash_map_for_each_fn_t *fn;
    void *user_data;
};

static OPT(i32) forward_callback(void *user_data, void *raw_element)
{
    struct for_each_opts *opts = user_data;
    hash_map_bucket_element_t *element = raw_element;

    return (opts->fn(opts->user_data, &element->pair));
}

OPT(i32) hash_map_for_each(hash_map_t *self, hash_map_for_each_fn_t *fn,
    void *user_data)
{
    struct for_each_opts opts = {fn, user_data};
    OPT(i32) val = NONE(i32);

    for (usize_t i = 0; !val.is_some && i < self->bucket_count; i++)
        if (self->buckets[i])
            val = list_for_each(self->buckets[i], &forward_callback, &opts);
    return (val);
}
