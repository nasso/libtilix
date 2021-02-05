/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_map_remove
*/

#include "my/my.h"
#include "my/cstr.h"
#include "my/collections/list.h"
#include "my/collections/hash_map.h"
#include "priv.h"

static bool find_callback(void *user_data, void *raw_element)
{
    const char *key = user_data;
    hash_map_bucket_element_t *element = raw_element;

    return (my_cstrcmp(key, element->pair.key) == 0);
}

OPT(ptr) hash_map_remove(hash_map_t *self, const char *key)
{
    u64_t hash = self->fn(key);
    list_t *bucket = self->buckets[hash % self->bucket_count];
    hash_map_bucket_element_t *elem = NULL;
    OPT(ptr) elem_ptr = NONE(ptr);
    void *value = NULL;

    if (bucket == NULL)
        return (NONE(ptr));
    elem_ptr = list_remove_element(bucket, (void*) key, &find_callback);
    if (!elem_ptr.is_some)
        return (NONE(ptr));
    elem = elem_ptr.v;
    self->size--;
    if (elem) {
        value = elem->pair.value;
        my_free((void*) elem->pair.key);
        my_free(elem);
    }
    return (SOME(ptr, value));
}
