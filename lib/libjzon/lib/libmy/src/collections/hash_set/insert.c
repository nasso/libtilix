/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set_insert
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "my/collections/hash_set.h"
#include "priv.h"

OPT_DEFINE(hash_set_bucket_element_t*, bucket_elem)

struct find_elem_with_key_data {
    hash_set_t *self;
    void *value;
};

static const double MAX_LOAD_FACTOR = 0.75;

static bool find_elem_with_key(void *user_data, void *raw_element)
{
    struct find_elem_with_key_data *data = user_data;
    hash_set_bucket_element_t *elem = raw_element;

    if (data->self->eq)
        return (data->self->eq(data->value, elem->value));
    return (data->value == elem->value);
}

static bool ensure_exists(list_t **bucket_ptr)
{
    if (*bucket_ptr)
        return (false);
    *bucket_ptr = list_new();
    return (*bucket_ptr == NULL);
}

static OPT(bucket_elem) get_element(hash_set_t *self, void *value)
{
    u64_t hash = self->fn(value);
    list_t **bucket_ptr = self->buckets + (hash % self->bucket_count);
    hash_set_bucket_element_t *elem = NULL;
    struct find_elem_with_key_data cb_data = { self, value };
    OPT(ptr) opt_elem = NONE(ptr);

    if (ensure_exists(bucket_ptr))
        return (NONE(bucket_elem));
    opt_elem = list_find_with(*bucket_ptr, &find_elem_with_key, &cb_data);
    if (opt_elem.is_some)
        return (SOME(bucket_elem, opt_elem.v));
    elem = hash_set__bucket_element_new(hash, value);
    if (elem == NULL || list_push_back(*bucket_ptr, elem)) {
        hash_set__bucket_element_destroy(elem);
        return (NONE(bucket_elem));
    }
    self->size++;
    return (SOME(bucket_elem, elem));
}

bool hash_set_insert(hash_set_t *self, void *value)
{
    OPT(bucket_elem) elem = get_element(self, value);

    if (!elem.is_some)
        return (true);
    if (((double) self->size / (double) self->bucket_count) >= MAX_LOAD_FACTOR)
        if (hash_set__grow(self, (usize_t) (self->bucket_count * (4.0 / 3.0))))
            return (true);
    elem.v->value = value;
    return (false);
}
