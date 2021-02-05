/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set_remove
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "my/collections/hash_set.h"
#include "priv.h"

struct find_cb_data {
    hash_set_t *self;
    const void *value;
};

static bool find_cb(void *ptr, void *elemptr)
{
    struct find_cb_data *cb_data = ptr;
    hash_set_bucket_element_t *elem = elemptr;

    if (cb_data->self->eq)
        return (cb_data->self->eq(elem->value, cb_data->value));
    return (elem->value == cb_data->value);
}

const void *hash_set_remove(hash_set_t *self, const void *value)
{
    u64_t hash = self->fn(value);
    list_t *bucket = self->buckets[hash % self->bucket_count];
    hash_set_bucket_element_t *elem = NULL;
    struct find_cb_data cb_data = {self, value};
    OPT(ptr) elem_ptr = NONE(ptr);

    if (bucket == NULL)
        return (NULL);
    elem_ptr = list_remove_element(bucket, &cb_data, &find_cb);
    if (!elem_ptr.is_some)
        return (NULL);
    elem = elem_ptr.v;
    self->size--;
    if (elem) {
        value = elem->value;
        my_free(elem);
    }
    return (value);
}
