/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_geti implementation
*/

#include "my/my.h"
#include "my/collections/vec.h"
#include "jzon/jzon.h"

jzon_t jzon_geti(const jzon_t self, usize_t index)
{
    OPT(ptr) ptr_val = NONE(ptr);

    if (self->v->type != JZ_ARR)
        return (NULL);
    ptr_val = vec_get(self->v->u.arr, index);
    return (ptr_val.is_some ? jzon_iref(ptr_val.v) : NULL);
}
