/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON create_arr conarructor
*/

#include "my/my.h"
#include "jzon/jzon.h"

jzon_t jzon_create_arr(void)
{
    jzon_t jz = jzon_create(JZ_ARR);

    if (jz == NULL)
        return (NULL);
    jz->v->u.arr = vec_new();
    if (jz->v->u.arr == NULL) {
        jzon_drop(jz);
        return (NULL);
    }
    return (jz);
}
