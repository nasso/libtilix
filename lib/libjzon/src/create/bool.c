/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON create_bool conbooluctor
*/

#include "my/my.h"
#include "jzon/jzon.h"

jzon_t jzon_create_bool(bool val)
{
    jzon_t jz = jzon_create(JZ_BOOL);

    if (jz == NULL)
        return (NULL);
    jz->v->u.bool_val = val;
    return (jz);
}
