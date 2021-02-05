/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON get*_num functions implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

f64_t jzon_getq_num(const jzon_t self, const char *query)
{
    const jzon_t jz = jzon_getq(self, query);
    f64_t val = 0.0;

    if (jz == NULL)
        return (val);
    val = jzon_num(jz);
    jzon_drop(jz);
    return (val);
}

f64_t jzon_getk_num(const jzon_t self, const char *key)
{
    const jzon_t jz = jzon_getk(self, key);
    f64_t val = 0.0;

    if (jz == NULL)
        return (val);
    val = jzon_num(jz);
    jzon_drop(jz);
    return (val);
}

f64_t jzon_geti_num(const jzon_t self, usize_t index)
{
    const jzon_t jz = jzon_geti(self, index);
    f64_t val = 0.0;

    if (jz == NULL)
        return (val);
    val = jzon_num(jz);
    jzon_drop(jz);
    return (val);
}
