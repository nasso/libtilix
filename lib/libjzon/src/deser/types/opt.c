/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON is_some and is_none deserializers
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool is_some_deser(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((bool*) dest) = jz != NULL;
    return (false);
}

static bool is_none_deser(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((bool*) dest) = jz == NULL;
    return (false);
}

const jzon_type_desc_t JZON_IS_SOME_TYPE_DESC = {
    .primitive = JZ_ANY,
    .size = sizeof(bool),
    .deser_func = &is_some_deser,
};

const jzon_type_desc_t JZON_IS_NONE_TYPE_DESC = {
    .primitive = JZ_ANY,
    .size = sizeof(bool),
    .deser_func = &is_none_deser,
};
