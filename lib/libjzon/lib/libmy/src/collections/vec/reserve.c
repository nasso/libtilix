/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Vec reserve method
*/

#include "my/my.h"
#include "my/collections/vec.h"

static const f64_t MIN_GROW_FACTOR = 2.0;

static bool grow(vec_t *self, usize_t new_size)
{
    void **data = my_malloc(new_size * sizeof(void*));

    if (data == NULL)
        return (true);
    my_memcpy(data, self->data, self->len * sizeof(void*));
    my_free(self->data);
    self->data = data;
    self->capacity = new_size;
    return (false);
}

bool vec_reserve(vec_t *self, usize_t additional)
{
    usize_t min_grow = self->capacity * MIN_GROW_FACTOR;
    usize_t req_grow = self->len + additional;

    if (self->capacity - self->len >= additional)
        return (false);
    return (grow(self, usize_max(min_grow, req_grow)));
}
