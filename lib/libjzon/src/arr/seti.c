/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_seti implementation
*/

#include "my/my.h"
#include "my/collections/vec.h"
#include "jzon/jzon.h"

bool jzon_seti(jzon_t self, usize_t index, jzon_t element)
{
    OPT(ptr) old_val = NONE(ptr);

    if (self->v->type != JZ_ARR)
        return (true);
    old_val = vec_set((vec_t*) self->v->u.arr, index, element);
    if (!old_val.is_some)
        return (true);
    jzon_drop(old_val.v);
    return (false);
}
