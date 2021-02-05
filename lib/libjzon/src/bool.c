/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_bool implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

bool jzon_bool(const jzon_t self)
{
    if (self->v->type != JZ_BOOL)
        return (true);
    return (self->v->u.bool_val);
}

bool jzon_set_bool(jzon_t self, bool val)
{
    if (self->v->type != JZ_BOOL)
        return (true);
    self->v->u.bool_val = val;
    return (false);
}
