/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_insert
*/

#include "my/my.h"
#include "my/cstr.h"
#include "my/collections/list.h"
#include "my/collections/hash_map.h"
#include "priv.h"

OPT_DEFINE(hash_map_bucket_element_t*, bucket_elem)

static const double MAX_LOAD_FACTOR = 0.75;

static bool find_elem_with_key(void *user_data, void *raw_element)
{
    const char *key = user_data;
    hash_map_bucket_element_t *elem = raw_element;

    return (my_cstrcmp(key, elem->pair.key) == 0);
}

static bool ensure_exists(list_t **bucket_ptr)
{
    if (*bucket_ptr)
        return (false);
    *bucket_ptr = list_new();
    return (*bucket_ptr == NULL);
}

static OPT(bucket_elem) get_element(hash_map_t *self, const char *key)
{
    u64_t hash = self->fn(key);
    list_t **bucket_ptr = self->buckets + (hash % self->bucket_count);
    hash_map_bucket_element_t *elem = NULL;
    OPT(ptr) opt_elem = NONE(ptr);

    if (ensure_exists(bucket_ptr))
        return (NONE(bucket_elem));
    opt_elem = list_find_with(*bucket_ptr, &find_elem_with_key, (void*) key);
    if (opt_elem.is_some)
        return (SOME(bucket_elem, opt_elem.v));
    elem = hash_map__bucket_element_new(hash, key);
    if (elem == NULL || list_push_back(*bucket_ptr, elem)) {
        hash_map__bucket_element_destroy(elem);
        return (NONE(bucket_elem));
    }
    self->size++;
    return (SOME(bucket_elem, elem));
}

RES(hash_map_insert) hash_map_insert(hash_map_t *self, const char *key,
    void *value)
{
    OPT(ptr) old_value = hash_map_get(self, key);
    OPT(bucket_elem) elem = get_element(self, key);

    if (!elem.is_some)
        return (RES_ERR(hash_map_insert, true));
    if (((double) self->size / (double) self->bucket_count) >= MAX_LOAD_FACTOR)
        if (hash_map__grow(self, (usize_t) (self->bucket_count * (4.0 / 3.0))))
            return (RES_ERR(hash_map_insert, true));
    elem.v->pair.value = value;
    return (RES_OK(hash_map_insert, old_value));
}
