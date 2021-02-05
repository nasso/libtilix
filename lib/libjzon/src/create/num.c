/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON create_num conbooluctor
*/

#include "my/my.h"
#include "jzon/jzon.h"

jzon_t jzon_create_num(f64_t val)
{
    jzon_t jz = jzon_create(JZ_NUM);

    if (jz == NULL)
        return (NULL);
    jz->v->u.num = val;
    return (jz);
}
