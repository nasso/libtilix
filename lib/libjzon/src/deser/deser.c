/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON deserializer
*/

#include "jzon/jzon.h"
#include "jzon/deser.h"

static jzon_t get_match(const jzon_t jz, const jzon_deser_field_t *field)
{
    jzon_t sub_jz = jzon_getq(jz, field->match);

    if (sub_jz == NULL && field->default_json != NULL)
        sub_jz = jzon_from(field->default_json);
    if (sub_jz == NULL && field->default_func != NULL)
        sub_jz = field->default_func(jz, &field->params);
    return (sub_jz);
}

static bool deser_struct(const jzon_t jz, const jzon_type_desc_t *type_desc,
    void *dest)
{
    bool err = jz == NULL;
    const jzon_deser_field_t *field = NULL;
    jzon_t sub_jz = NULL;

    for (usize_t i = 0; !err && i < JZON_DESER_MAX_FIELD_COUNT &&
        type_desc->fields[i].match; i++) {
        field = &type_desc->fields[i];
        sub_jz = get_match(jz, field);
        err = jzon_deser(sub_jz, field->type, &field->params,
            (char*) dest + field->offset);
        if (sub_jz != NULL)
            jzon_drop(sub_jz);
        err &= !field->optional;
    }
    return (err);
}

bool jzon_deser(const jzon_t jz, const jzon_type_desc_t *type_desc,
    const jzon_deser_params_t *params, void *dest)
{
    if (type_desc->primitive != JZ_ANY &&
        (jz == NULL || jz->v->type != type_desc->primitive))
        return (true);
    else if (type_desc->deser_func)
        return (type_desc->deser_func(jz, params, dest));
    return (deser_struct(jz, type_desc, dest));
}
