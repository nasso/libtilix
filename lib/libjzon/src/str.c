/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_str implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

const char *jzon_str(const jzon_t self)
{
    if (self->v->type != JZ_STR)
        return (NULL);
    return (self->v->u.str);
}

bool jzon_set_str(jzon_t self, const char *str)
{
    char *val = NULL;

    if (self->v->type != JZ_STR)
        return (true);
    val = my_cstrdup(str);
    if (val == NULL)
        return (true);
    my_free((char*) self->v->u.str);
    self->v->u.str = val;
    return (false);
}
