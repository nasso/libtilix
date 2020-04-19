/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled layer parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/common.h"
#include "tilix/property.h"
#include "tilix/chunk.h"
#include "tilix/layer.h"

const jzon_type_desc_t TL_LAYER_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_layer_t),
    .fields = {
        {
            .match = ".id",
            .offset = offsetof(tl_layer_t, id),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".name",
            .offset = offsetof(tl_layer_t, name),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".x",
            .offset = offsetof(tl_layer_t, x),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".y",
            .offset = offsetof(tl_layer_t, y),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".width",
            .offset = offsetof(tl_layer_t, width),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".height",
            .offset = offsetof(tl_layer_t, height),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".startx",
            .offset = offsetof(tl_layer_t, startx),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".starty",
            .offset = offsetof(tl_layer_t, starty),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".offsetx",
            .offset = offsetof(tl_layer_t, offsetx),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".offsety",
            .offset = offsetof(tl_layer_t, offsety),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".opacity",
            .offset = offsetof(tl_layer_t, opacity),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".visible",
            .offset = offsetof(tl_layer_t, visible),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".type",
            .offset = offsetof(tl_layer_t, type),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "tilelayer", TL_LAYER_TILELAYER },
                { "objectgroup", TL_LAYER_OBJECTGROUP },
                { "imagelayer", TL_LAYER_IMAGELAYER },
                { "group", TL_LAYER_GROUP },
            },
        },
        {
            .match = ".chunks",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.tilelayer.chunks.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_CHUNK_TYPE_DESC,
        },
        {
            .match = ".chunks",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.tilelayer.chunks.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".compression",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.tilelayer.compression),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "zlib", TL_LAYER_ZLIB },
                { "gzip", TL_LAYER_GZIP },
            },
        },
        {
            .match = ".data",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.tilelayer.data.gids),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".data",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.tilelayer.data.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".encoding",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.tilelayer.encoding),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "csv", TL_LAYER_CSV },
                { "base64", TL_LAYER_BASE64 },
            },
        },
        {
            .match = ".draworder",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.objectgroup.draworder),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "topdown", TL_LAYER_TOPDOWN },
                { "index", TL_LAYER_INDEX },
            },
        },
        {
            .match = ".objects",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.objectgroup.objects.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_OBJECT_TYPE_DESC,
        },
        {
            .match = ".objects",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.objectgroup.objects.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".transparentcolor",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.imagelayer.transparentcolor),
            .type = &TL_COLOR_STR_TYPE_DESC,
        },
        {
            .match = ".image",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.imagelayer.image),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".layers",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.group.layers.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_LAYER_TYPE_DESC,
        },
        {
            .match = ".layers",
            .optional = true,
            .offset = offsetof(tl_layer_t, u.group.layers.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".properties",
            .offset = offsetof(tl_layer_t, properties),
            .type = &TL_PROPERTIES_TYPE_DESC,
        },
    },
};

static void dispose_types(tl_layer_t *self)
{
    switch (self->type) {
    case TL_LAYER_TILELAYER:
        for (usize_t i = 0; i < self->u.tilelayer.chunks.len; i++)
            tl_chunk_dispose(&self->u.tilelayer.chunks.data[i]);
        my_free(self->u.tilelayer.chunks.data);
        my_free(self->u.tilelayer.data.gids);
        break;
    case TL_LAYER_OBJECTGROUP:
        for (usize_t i = 0; i < self->u.objectgroup.objects.len; i++)
            tl_object_dispose(&self->u.objectgroup.objects.data[i]);
        my_free(self->u.objectgroup.objects.data);
        break;
    case TL_LAYER_IMAGELAYER:
        my_free(self->u.imagelayer.image);
        break;
    case TL_LAYER_GROUP:
        for (usize_t i = 0; i < self->u.group.layers.len; i++)
            tl_layer_dispose(&self->u.group.layers.data[i]);
        my_free(self->u.group.layers.data);
    }
}

void tl_layer_dispose(tl_layer_t *self)
{
    my_free(self->name);
    dispose_types(self);
    for (usize_t i = 0; i < self->properties.len; i++)
        my_free(&self->properties.data[i]);
    my_free(self->properties.data);
}
