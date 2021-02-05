/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON get*_str functions implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

const char *jzon_getq_str(const jzon_t self, const char *query)
{
    const jzon_t jz = jzon_getq(self, query);
    const char *val = NULL;

    if (jz == NULL)
        return (val);
    val = jzon_str(jz);
    jzon_drop(jz);
    return (val);
}

const char *jzon_getk_str(const jzon_t self, const char *key)
{
    const jzon_t jz = jzon_getk(self, key);
    const char *val = NULL;

    if (jz == NULL)
        return (val);
    val = jzon_str(jz);
    jzon_drop(jz);
    return (val);
}

const char *jzon_geti_str(const jzon_t self, usize_t index)
{
    const jzon_t jz = jzon_geti(self, index);
    const char *val = NULL;

    if (jz == NULL)
        return (val);
    val = jzon_str(jz);
    jzon_drop(jz);
    return (val);
}
