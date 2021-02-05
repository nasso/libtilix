/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON unsigned primitive type descriptors
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool jzon_deser_u8(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((u8_t*) dest) = jzon_num(jz);
    return (false);
}

static bool jzon_deser_u16(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((u16_t*) dest) = jzon_num(jz);
    return (false);
}

static bool jzon_deser_u32(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((u32_t*) dest) = jzon_num(jz);
    return (false);
}

static bool jzon_deser_u64(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((u64_t*) dest) = jzon_num(jz);
    return (false);
}

static bool jzon_deser_usize(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    (void)(params);
    *((usize_t*) dest) = jzon_num(jz);
    return (false);
}

const jzon_type_desc_t JZON_U8_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_u8,
    .size = sizeof(u8_t),
};

const jzon_type_desc_t JZON_U16_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_u16,
    .size = sizeof(u16_t),
};

const jzon_type_desc_t JZON_U32_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_u32,
    .size = sizeof(u32_t),
};

const jzon_type_desc_t JZON_U64_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_u64,
    .size = sizeof(u64_t),
};

const jzon_type_desc_t JZON_USIZE_TYPE_DESC = {
    .primitive = JZ_NUM,
    .deser_func = &jzon_deser_usize,
    .size = sizeof(usize_t),
};
