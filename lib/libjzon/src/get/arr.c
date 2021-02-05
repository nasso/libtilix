/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON get*_obj functions implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

jzon_t jzon_getq_arr(const jzon_t self, const char *query)
{
    const jzon_t jz = jzon_getq(self, query);

    if (jz == NULL)
        return (NULL);
    if (jz->v->type != JZ_ARR) {
        jzon_drop(jz);
        return (NULL);
    }
    return (jz);
}

jzon_t jzon_getk_arr(const jzon_t self, const char *key)
{
    const jzon_t jz = jzon_getk(self, key);

    if (jz == NULL)
        return (NULL);
    if (jz->v->type != JZ_ARR) {
        jzon_drop(jz);
        return (NULL);
    }
    return (jz);
}

jzon_t jzon_geti_arr(const jzon_t self, usize_t index)
{
    const jzon_t jz = jzon_geti(self, index);

    if (jz == NULL)
        return (NULL);
    if (jz->v->type != JZ_ARR) {
        jzon_drop(jz);
        return (NULL);
    }
    return (jz);
}
