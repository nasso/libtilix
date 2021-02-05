/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON get*_bool functions implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

bool jzon_getq_bool(const jzon_t self, const char *query)
{
    const jzon_t jz = jzon_getq(self, query);
    bool val = false;

    if (jz == NULL)
        return (val);
    val = jzon_bool(jz);
    jzon_drop(jz);
    return (val);
}

bool jzon_getk_bool(const jzon_t self, const char *key)
{
    const jzon_t jz = jzon_getk(self, key);
    bool val = false;

    if (jz == NULL)
        return (val);
    val = jzon_bool(jz);
    jzon_drop(jz);
    return (val);
}

bool jzon_geti_bool(const jzon_t self, usize_t index)
{
    const jzon_t jz = jzon_geti(self, index);
    bool val = false;

    if (jz == NULL)
        return (val);
    val = jzon_bool(jz);
    jzon_drop(jz);
    return (val);
}
