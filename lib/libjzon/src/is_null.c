/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON is_null implementation
*/

#include "jzon/jzon.h"

bool jzon_is_null(const jzon_t jz)
{
    if (jz == NULL)
        return (false);
    return (jz->v->type == JZ_NULL);
}
