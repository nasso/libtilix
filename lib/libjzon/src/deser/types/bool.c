/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON boolean deserializer
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool jzon_deser_bool(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((bool*) dest) = jzon_bool(jz);
    return (false);
}

const jzon_type_desc_t JZON_BOOL_TYPE_DESC = {
    .primitive = JZ_BOOL,
    .deser_func = &jzon_deser_bool,
    .size = sizeof(bool),
};
