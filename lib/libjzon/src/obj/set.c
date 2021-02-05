/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_getq and jzon_getk implementations
*/

#include "my/my.h"
#include "my/collections/hash_map.h"
#include "jzon/jzon.h"

bool jzon_setq(jzon_t self, const char *query, jzon_t element)
{
    (void)(self);
    (void)(query);
    (void)(element);
    return (true);
}

bool jzon_setk(jzon_t self, const char *key, jzon_t element)
{
    RES(hash_map_insert) insert_res = RES_OK(hash_map_insert, NONE(ptr));

    if (self->v->type != JZ_OBJ)
        return (true);
    insert_res = hash_map_insert((hash_map_t*) self->v->u.obj, key, element);
    if (!insert_res.is_ok)
        return (true);
    else if (insert_res.u.ok.is_some)
        jzon_drop(insert_res.u.ok.v);
    return (false);
}
