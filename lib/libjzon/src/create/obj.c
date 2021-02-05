/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON create_obj conobjuctor
*/

#include "my/my.h"
#include "my/collections/hash_map.h"
#include "jzon/jzon.h"

jzon_t jzon_create_obj(void)
{
    jzon_t jz = jzon_create(JZ_OBJ);

    if (jz == NULL)
        return (NULL);
    jz->v->u.obj = hash_map_new();
    if (jz->v->u.obj == NULL) {
        jzon_drop(jz);
        return (NULL);
    }
    return (jz);
}
