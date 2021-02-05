/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON create_str constructor
*/

#include "my/my.h"
#include "jzon/jzon.h"

jzon_t jzon_create_str(const char *val)
{
    jzon_t jz = jzon_create(JZ_STR);

    if (jz == NULL)
        return (NULL);
    jz->v->u.str = my_cstrdup(val);
    if (jz->v->u.str == NULL) {
        jzon_drop(jz);
        return (NULL);
    }
    return (jz);
}
