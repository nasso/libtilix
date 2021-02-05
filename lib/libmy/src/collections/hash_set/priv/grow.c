/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set__grow
*/

#include "my/my.h"
#include "my/collections/list.h"
#include "my/collections/hash_set.h"
#include "../priv.h"

struct grow_op_data {
    list_t **buckets;
    usize_t bucket_count;
    bool err;
};

static OPT(i32) export_entry_callback(void *user_data, void *raw_element)
{
    struct grow_op_data *data = user_data;
    hash_set_bucket_element_t *element = raw_element;
    list_t **bucket = &data->buckets[element->hash % data->bucket_count];

    if (*bucket == NULL) {
        *bucket = list_from(1, element);
        if (*bucket == NULL) {
            data->err = true;
            return (SOME(i32, 1));
        }
    } else
        data->err = list_push_back(*bucket, element);
    return (data->err ? SOME(i32, 1) : NONE(i32));
}

static bool export_entries(hash_set_t *self, struct grow_op_data *data)
{
    if (self->buckets == NULL)
        return (false);
    for (usize_t i = 0; !data->err && i < self->bucket_count; i++)
        if (self->buckets[i])
            list_for_each(self->buckets[i], &export_entry_callback, data);
    if (!data->err)
        return (false);
    for (usize_t i = 0; i < data->bucket_count; i++)
        if (data->buckets[i] != NULL)
            list_destroy(data->buckets[i]);
    my_memset(data->buckets, 0, sizeof(list_t*) * data->bucket_count);
    return (true);
}

bool hash_set__grow(hash_set_t *self, usize_t new_size)
{
    struct grow_op_data data = {
        .buckets = my_calloc(new_size, sizeof(list_t*)),
        .bucket_count = new_size,
    };

    if (data.buckets == NULL)
        return (true);
    else if (export_entries(self, &data) || data.err) {
        my_free(data.buckets);
        return (true);
    }
    for (usize_t i = 0; i < self->bucket_count; i++)
        if (self->buckets[i])
            list_destroy(self->buckets[i]);
    my_free(self->buckets);
    self->bucket_count = new_size;
    self->buckets = data.buckets;
    return (false);
}
