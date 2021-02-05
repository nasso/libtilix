/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_num implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

f64_t jzon_num(const jzon_t self)
{
    if (self->v->type != JZ_NUM)
        return (0.0);
    return (self->v->u.num);
}

bool jzon_set_num(jzon_t self, f64_t num)
{
    if (self->v->type != JZ_NUM)
        return (true);
    self->v->u.num = num;
    return (false);
}
