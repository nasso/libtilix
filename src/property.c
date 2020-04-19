/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Property parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/common.h"
#include "tilix/property.h"

static bool parse_prop(tl_property_t *prop, const jzon_t jval)
{
    switch (prop->type) {
    case TL_STRING:
    case TL_FILE:
        return (jzon_deser(jval, &JZON_STR_TYPE_DESC, NULL, &prop->u.str));
    case TL_INT:
        return (jzon_deser(jval, &JZON_I64_TYPE_DESC, NULL, &prop->u.i));
    case TL_FLOAT:
        return (jzon_deser(jval, &JZON_F64_TYPE_DESC, NULL, &prop->u.f));
    case TL_BOOL:
        return (jzon_deser(jval, &JZON_BOOL_TYPE_DESC, NULL, &prop->u.b));
    case TL_COLOR:
        return (jzon_deser(jval, &TL_COLOR_STR_TYPE_DESC, NULL,
            &prop->u.color));
    }
    return (true);
}

static bool property_value_deser(const jzon_t jz,
    const jzon_deser_params_t *params, void *dest)
{
    tl_property_t *prop = dest;
    const jzon_t jval = jzon_getk(jz, "value");
    bool err = false;

    (void)(params);
    if (jval == NULL)
        return (true);
    err = parse_prop(prop, jval);
    jzon_drop(jval);
    return (err);
}

static const jzon_type_desc_t PROPERTY_VALUE_TYPE_DESC = {
    .primitive = JZ_ANY,
    .size = sizeof(tl_property_value_t),
    .deser_func = &property_value_deser,
};

const jzon_type_desc_t TL_PROPERTY_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_property_t),
    .fields = {
        {
            .match = ".name",
            .offset = offsetof(tl_property_t, name),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".type",
            .offset = offsetof(tl_property_t, type),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                {"string", TL_STRING},
                {"int", TL_INT},
                {"float", TL_FLOAT},
                {"bool", TL_BOOL},
                {"color", TL_COLOR},
                {"file", TL_FILE},
            },
        },
        {
            .match = "",
            .offset = 0,
            .type = &PROPERTY_VALUE_TYPE_DESC,
        },
    },
};

struct properties {
    tl_property_t *data;
    usize_t len;
};

const jzon_type_desc_t TL_PROPERTIES_TYPE_DESC = {
    .primitive = JZ_ARR,
    .size = sizeof(struct properties),
    .fields = {
        {
            .match = "",
            .offset = offsetof(struct properties, data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_PROPERTY_TYPE_DESC,
        },
        {
            .match = "",
            .offset = offsetof(struct properties, len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
    },
};

void tl_property_dispose(tl_property_t *self)
{
    my_free(self->name);
    if (self->type == TL_FILE || self->type == TL_STRING)
        my_free(self->u.str);
}
