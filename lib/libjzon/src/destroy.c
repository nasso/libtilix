/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON destroyer
*/

#include "my/my.h"
#include "jzon/jzon.h"

static OPT(i32) obj_destroy_cb(void *user_data, hash_map_pair_t *pair)
{
    jzon_t jz = pair->value;

    (void)(user_data);
    jzon_drop(jz);
    return (NONE(i32));
}

static OPT(i32) vec_destroy_cb(void *user_data, void *element)
{
    (void)(user_data);
    jzon_drop(element);
    return (NONE(i32));
}

void jzon__val_destroy(jzon_val_t *self)
{
    if (self == NULL)
        return;
    switch (self->type) {
    case JZ_STR:
        my_free((char*) self->u.str);
        break;
    case JZ_OBJ:
        hash_map_destroy_with((hash_map_t*) self->u.obj, &obj_destroy_cb, NULL);
        break;
    case JZ_ARR:
        vec_destroy_with((vec_t*) self->u.arr, &vec_destroy_cb, NULL);
    default:
        break;
    }
    my_free(self);
}
