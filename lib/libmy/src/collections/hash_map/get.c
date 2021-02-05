/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_get
*/

#include "my/my.h"
#include "my/cstr.h"
#include "my/collections/hash_map.h"
#include "my/collections/list.h"

static bool find_callback(void *user_data, void *raw_element)
{
    const char *key = user_data;
    hash_map_bucket_element_t *element = raw_element;

    return (my_cstrcmp(key, element->pair.key) == 0);
}

OPT(ptr) hash_map_get(const hash_map_t *self, const char *key)
{
    u64_t hash = self->fn(key);
    list_t *bucket = self->buckets[hash % self->bucket_count];
    hash_map_bucket_element_t *elem = NULL;
    OPT(ptr) elem_ptr = NONE(ptr);

    if (bucket == NULL)
        return (NONE(ptr));
    elem_ptr = list_find_with(bucket, &find_callback, (void*) key);
    if (elem_ptr.is_some) {
        elem = elem_ptr.v;
        return (SOME(ptr, elem->pair.value));
    }
    return (NONE(ptr));
}

bool hash_map_contains_key(const hash_map_t *self, const char *key)
{
    return (hash_map_get(self, key).is_some);
}
