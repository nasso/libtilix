/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON jzon_len implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

usize_t jzon_len(jzon_t self)
{
    const jzon_val_t *val = self->v;

    switch (val->type) {
    case JZ_STR:
        return (my_cstrlen(val->u.str));
    case JZ_OBJ:
        return (val->u.obj->size);
    case JZ_ARR:
        return (val->u.arr->len);
    default:
        return (0);
    }
}
