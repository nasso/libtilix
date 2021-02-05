/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON array deserializers
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool jzon_deser_arr_size(const jzon_t jz,
    const jzon_deser_params_t *params, void *dest)
{
    (void)(params);
    *((usize_t*) dest) = jzon_len(jz);
    return (false);
}

static bool jzon_deser_plain_arr(const jzon_t jz,
    const jzon_deser_params_t *params, void *dest)
{
    jzon_t element = NULL;
    bool err = false;
    void *arr = dest;

    if (params->item_type->size == 0 || jzon_len(jz) > params->max_size ||
        jzon_len(jz) < params->min_size)
        return (true);
    for (usize_t i = 0; i < jzon_len(jz); i++) {
        element = jzon_geti(jz, i);
        err = jzon_deser(element, params->item_type, NULL,
            ((char*) arr) + i * params->item_type->size);
        jzon_drop(element);
        if (err) {
            my_free(arr);
            return (true);
        }
    }
    return (false);
}

static bool jzon_deser_heap_arr(const jzon_t jz,
    const jzon_deser_params_t *params, void *dest)
{
    jzon_t element = NULL;
    bool err = false;
    void **arr = dest;

    if (params->item_type->size == 0)
        return (true);
    *arr = my_calloc(jzon_len(jz), params->item_type->size);
    if (*arr == NULL)
        return (true);
    for (usize_t i = 0; i < jzon_len(jz); i++) {
        element = jzon_geti(jz, i);
        err = jzon_deser(element, params->item_type, NULL,
            ((char*) *arr) + i * params->item_type->size);
        jzon_drop(element);
        if (err) {
            my_free(*arr);
            return (true);
        }
    }
    return (false);
}

const jzon_type_desc_t JZON_ARR_SIZE_TYPE_DESC = {
    .primitive = JZ_ARR,
    .deser_func = &jzon_deser_arr_size,
    .size = sizeof(usize_t),
};

const jzon_type_desc_t JZON_PLAIN_ARR_TYPE_DESC = {
    .primitive = JZ_ARR,
    .deser_func = &jzon_deser_plain_arr,
    .size = 0,
};

const jzon_type_desc_t JZON_HEAP_ARR_TYPE_DESC = {
    .primitive = JZ_ARR,
    .deser_func = &jzon_deser_heap_arr,
    .size = sizeof(void*),
    .is_ptr = true,
};
