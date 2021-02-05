/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON hash-map deserializers
*/

#include "my/my.h"
#include "my/collections/hash_map.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

struct clone_data {
    hash_map_t *map;
    const jzon_type_desc_t *item_type;
};

static OPT(i32) cloner(void *ptr, hash_map_pair_t *pair)
{
    struct clone_data *data = ptr;
    void *element_data = NULL;

    if (data->item_type->is_ptr) {
        if (jzon_deser(pair->value, data->item_type, NULL, &element_data) ||
            !hash_map_insert(data->map, pair->key, element_data).is_ok
        ) {
            return (SOME(i32, 1));
        }
    } else {
        element_data = my_malloc(data->item_type->size);
        if (element_data == NULL ||
            jzon_deser(pair->value, data->item_type, NULL, element_data) ||
            !hash_map_insert(data->map, pair->key, element_data).is_ok
        ) {
            my_free(element_data);
            return (SOME(i32, 1));
        }
    }
    return (NONE(i32));
}

static OPT(i32) destroyer(void *ptr, hash_map_pair_t *pair)
{
    (void)(ptr);
    my_free(pair->value);
    return (NONE(i32));
}

static bool jzon_deser_hash_map(const jzon_t jz,
    const jzon_deser_params_t *params, void *dest)
{
    hash_map_t *map = hash_map_new();
    struct clone_data data = { map, params->item_type };

    if (map == NULL)
        return (true);
    if (hash_map_for_each((hash_map_t*) jz->v->u.obj, &cloner, &data).is_some) {
        hash_map_destroy_with(map, &destroyer, NULL);
        return (true);
    }
    *((hash_map_t**) dest) = map;
    return (false);
}

const jzon_type_desc_t JZON_HASH_MAP_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .deser_func = &jzon_deser_hash_map,
    .size = sizeof(hash_map_t*),
    .is_ptr = true,
};
