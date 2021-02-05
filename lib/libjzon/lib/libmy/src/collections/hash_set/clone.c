/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set_clone
*/

#include "my/my.h"
#include "my/collections/hash_set.h"

struct clone_data {
    hash_set_t *set;
    void *(*clone)(const void*);
    void (*destroy)(void*);
};

static OPT(i32) clone_val_cb(void *user_data, void *value)
{
    struct clone_data *data = user_data;
    void *value_clone = data->clone ? data->clone(value) : value;

    if (hash_set_insert(data->set, value_clone)) {
        if (data->destroy)
            data->destroy(value_clone);
        return (SOME(i32, 1));
    }
    return (NONE(i32));
}

static OPT(i32) destroy_val_callback(void *user_data, void *value)
{
    struct clone_data *data = user_data;

    if (data->destroy)
        data->destroy(value);
    return (NONE(i32));
}

hash_set_t *hash_set_clone_with(const hash_set_t *other,
    void *(*clone)(const void*), void (*destroy)(void*))
{
    struct clone_data data = {
        .set = hash_set_with_eq_and_buckets(other->fn, other->eq,
            other->bucket_count),
        .clone = clone,
        .destroy = destroy,
    };

    if (data.set == NULL)
        return (NULL);
    if (hash_set_for_each((hash_set_t*) other, &clone_val_cb, &data).is_some) {
        hash_set_destroy_with(data.set, &destroy_val_callback, &data);
        return (NULL);
    }
    return (data.set);
}

hash_set_t *hash_set_clone(const hash_set_t *other)
{
    return (hash_set_clone_with(other, NULL, NULL));
}
