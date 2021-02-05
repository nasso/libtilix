/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Vector constructors
*/

#include <stddef.h>
#include "my/my.h"
#include "my/collections/vector.h"

vector_t *vector_new(size_t stride)
{
    return (vector_with_capacity(stride, 32));
}

vector_t *vector_from(size_t stride, size_t count, const void *data)
{
    vector_t *v = vector_with_capacity(stride, count);

    if (v != NULL) {
        my_memmove(v->data, data, stride * count);
        v->len = count;
    }
    return (v);
}

vector_t *vector_with_capacity(size_t stride, size_t capacity)
{
    vector_t *v = my_malloc(sizeof(vector_t));

    if (v == NULL)
        return (NULL);
    v->stride = stride;
    v->capacity = capacity;
    v->len = 0;
    v->data = my_malloc(v->stride * v->capacity);
    if (v->data == NULL) {
        my_free(v);
        return (NULL);
    }
    return (v);
}
