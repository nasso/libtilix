/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_arr_push implementation
*/

#include "my/my.h"
#include "my/collections/vec.h"
#include "jzon/jzon.h"

bool jzon_push(jzon_t self, jzon_t element)
{
    if (self->v->type != JZ_ARR)
        return (true);
    return (vec_push((vec_t*) self->v->u.arr, element));
}

bool jzon_pushi(jzon_t self, usize_t index, jzon_t element)
{
    if (self->v->type != JZ_ARR)
        return (true);
    return (vec_insert((vec_t*) self->v->u.arr, index, element));
}
