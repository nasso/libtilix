/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON floating point deserializers
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool jzon_deser_f32(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((f32_t*) dest) = jzon_num(jz);
    return (false);
}

static bool jzon_deser_f64(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((f64_t*) dest) = jzon_num(jz);
    return (false);
}

const jzon_type_desc_t JZON_F32_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_f32,
    .size = sizeof(f32_t),
};

const jzon_type_desc_t JZON_F64_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_f64,
    .size = sizeof(f64_t),
};
