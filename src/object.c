/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled object parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/common.h"
#include "tilix/property.h"
#include "tilix/object.h"

const jzon_type_desc_t TL_TEXT_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_text_t),
    .fields = {
        {
            .match = ".bold",
            .default_json = "false",
            .offset = offsetof(tl_text_t, bold),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".color",
            .default_json = "\"#000000\"",
            .offset = offsetof(tl_text_t, color),
            .type = &TL_COLOR_STR_TYPE_DESC,
        },
        {
            .match = ".fontfamily",
            .default_json = "\"sans-serif\"",
            .offset = offsetof(tl_text_t, fontfamily),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".halign",
            .default_json = "\"left\"",
            .offset = offsetof(tl_text_t, halign),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "center", TL_HALIGN_CENTER },
                { "right", TL_HALIGN_RIGHT },
                { "justify", TL_HALIGN_JUSTIFY },
                { "left", TL_HALIGN_LEFT },
            },
        },
        {
            .match = ".italic",
            .default_json = "false",
            .offset = offsetof(tl_text_t, italic),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".kerning",
            .default_json = "true",
            .offset = offsetof(tl_text_t, kerning),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".pixelsize",
            .default_json = "16",
            .offset = offsetof(tl_text_t, pixelsize),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".strikeout",
            .default_json = "false",
            .offset = offsetof(tl_text_t, strikeout),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".text",
            .offset = offsetof(tl_text_t, text),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".underline",
            .default_json = "false",
            .offset = offsetof(tl_text_t, underline),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".valign",
            .default_json = "\"top\"",
            .offset = offsetof(tl_text_t, valign),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "center", TL_VALIGN_CENTER },
                { "bottom", TL_VALIGN_BOTTOM },
                { "top", TL_VALIGN_TOP },
            },
        },
        {
            .match = ".wrap",
            .default_json = "false",
            .offset = offsetof(tl_text_t, wrap),
            .type = &JZON_BOOL_TYPE_DESC,
        },
    },
};

void tl_text_deinit(tl_text_t *self)
{
    my_free(self->fontfamily);
    my_free(self->text);
}

const jzon_type_desc_t TL_POINT_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_point_t),
    .fields = {
        {
            .match = ".x",
            .offset = offsetof(tl_point_t, x),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".y",
            .offset = offsetof(tl_point_t, y),
            .type = &JZON_F64_TYPE_DESC,
        },
    },
};

static bool deser_kind(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    tl_object_t *obj = dest;

    (void)(params);
    obj->kind = TL_OBJ_RECT;
    obj->kind = jzon_getk_bool(jz, "ellipse") ? TL_OBJ_ELLIPSE : obj->kind;
    obj->kind = jzon_getk_bool(jz, "point") ? TL_OBJ_POINT : obj->kind;
    obj->kind = jzon_getq_str(jz, ".text.text") ? TL_OBJ_TEXT : obj->kind;
    obj->kind = jzon_getk_len(jz, "polygon") > 0 ? TL_OBJ_POLYGON : obj->kind;
    obj->kind = jzon_getk_len(jz, "polyline") > 0 ? TL_OBJ_POLYLINE : obj->kind;
    obj->kind = jzon_getk_num(jz, "gid") > 0 ? TL_OBJ_TILE : obj->kind;
    return (false);
}

static const jzon_type_desc_t OBJECT_KIND_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_object_kind_t),
    .deser_func = &deser_kind,
};

const jzon_type_desc_t TL_OBJECT_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_object_t),
    .fields = {
        {
            .match = "",
            .offset = offsetof(tl_object_t, kind),
            .type = &OBJECT_KIND_TYPE_DESC,
        },
        {
            .match = ".height",
            .offset = offsetof(tl_object_t, height),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".id",
            .offset = offsetof(tl_object_t, id),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".name",
            .offset = offsetof(tl_object_t, name),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".properties",
            .default_json = "[]",
            .offset = offsetof(tl_object_t, properties),
            .type = &TL_PROPERTIES_TYPE_DESC,
        },
        {
            .match = ".rotation",
            .offset = offsetof(tl_object_t, rotation),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".template",
            .optional = true,
            .offset = offsetof(tl_object_t, template),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".type",
            .offset = offsetof(tl_object_t, type),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".visible",
            .offset = offsetof(tl_object_t, visible),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".width",
            .offset = offsetof(tl_object_t, width),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".x",
            .offset = offsetof(tl_object_t, x),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".y",
            .offset = offsetof(tl_object_t, y),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".gid",
            .optional = true,
            .offset = offsetof(tl_object_t, gid),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".polygon",
            .optional = true,
            .offset = offsetof(tl_object_t, polygon.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_POINT_TYPE_DESC,
        },
        {
            .match = ".polygon",
            .optional = true,
            .offset = offsetof(tl_object_t, polygon.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".polyline",
            .optional = true,
            .offset = offsetof(tl_object_t, polyline.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_POINT_TYPE_DESC,
        },
        {
            .match = ".polyline",
            .optional = true,
            .offset = offsetof(tl_object_t, polyline.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".text",
            .optional = true,
            .offset = offsetof(tl_object_t, text),
            .type = &TL_TEXT_TYPE_DESC,
        },
    },
};

void tl_object_deinit(tl_object_t *self)
{
    my_free(self->name);
    for (usize_t i = 0; i < self->properties.len; i++)
        tl_property_deinit(&self->properties.data[i]);
    my_free(self->template);
    my_free(self->type);
    switch (self->kind) {
    case TL_OBJ_POLYGON:
        my_free(self->polygon.data);
        break;
    case TL_OBJ_POLYLINE:
        my_free(self->polyline.data);
        break;
    case TL_OBJ_TEXT:
        tl_text_deinit(&self->text);
    default:
        break;
    }
}
