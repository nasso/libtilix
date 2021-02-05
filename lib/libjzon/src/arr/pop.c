/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_arr_pop implementation
*/

#include "my/my.h"
#include "my/collections/vec.h"
#include "jzon/jzon.h"

jzon_t jzon_pop(jzon_t self)
{
    OPT(ptr) val = NONE(ptr);

    if (self->v->type != JZ_ARR)
        return (NULL);
    val = vec_pop((vec_t*) self->v->u.arr);
    return (val.is_some ? val.v : NULL);
}

jzon_t jzon_popi(jzon_t self, usize_t index)
{
    OPT(ptr) val = NONE(ptr);

    if (self->v->type != JZ_ARR)
        return (NULL);
    val = vec_remove((vec_t*) self->v->u.arr, index);
    return (val.is_some ? val.v : NULL);
}
