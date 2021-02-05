/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON get*_len functions implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

usize_t jzon_getq_len(const jzon_t self, const char *query)
{
    const jzon_t jz = jzon_getq(self, query);
    usize_t val = 0;

    if (jz == NULL)
        return (val);
    val = jzon_len(jz);
    jzon_drop(jz);
    return (val);
}

usize_t jzon_getk_len(const jzon_t self, const char *key)
{
    const jzon_t jz = jzon_getk(self, key);
    usize_t val = 0;

    if (jz == NULL)
        return (val);
    val = jzon_len(jz);
    jzon_drop(jz);
    return (val);
}

usize_t jzon_geti_len(const jzon_t self, usize_t index)
{
    const jzon_t jz = jzon_geti(self, index);
    usize_t val = 0;

    if (jz == NULL)
        return (val);
    val = jzon_len(jz);
    jzon_drop(jz);
    return (val);
}
