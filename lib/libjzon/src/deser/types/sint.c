/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON unsigned primitive type descriptors
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool jzon_deser_i8(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((i8_t*) dest) = jzon_num(jz);
    return (false);
}

static bool jzon_deser_i16(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((i16_t*) dest) = jzon_num(jz);
    return (false);
}

static bool jzon_deser_i32(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((i32_t*) dest) = jzon_num(jz);
    return (false);
}

static bool jzon_deser_i64(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((i64_t*) dest) = jzon_num(jz);
    return (false);
}

static bool jzon_deser_isize(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((isize_t*) dest) = jzon_num(jz);
    return (false);
}

const jzon_type_desc_t JZON_I8_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_i8,
    .size = sizeof(i8_t),
};

const jzon_type_desc_t JZON_I16_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_i16,
    .size = sizeof(i16_t),
};

const jzon_type_desc_t JZON_I32_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_i32,
    .size = sizeof(i32_t),
};

const jzon_type_desc_t JZON_I64_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_i64,
    .size = sizeof(i64_t),
};

const jzon_type_desc_t JZON_ISIZE_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_isize,
    .size = sizeof(isize_t),
};
