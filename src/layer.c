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
            .optional = true,
            .offset = offsetof(tl_layer_t, startx),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".starty",
            .optional = true,
            .offset = offsetof(tl_layer_t, starty),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".offsetx",
            .default_json = "0",
            .offset = offsetof(tl_layer_t, offsetx),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".offsety",
            .default_json = "0",
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
            .offset = offsetof(tl_layer_t, chunks.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_CHUNK_TYPE_DESC,
        },
        {
            .match = ".chunks",
            .optional = true,
            .offset = offsetof(tl_layer_t, chunks.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".compression",
            .default_json = "\"\"",
            .offset = offsetof(tl_layer_t, compression),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "", TL_LAYER_NONE },
                { "zlib", TL_LAYER_ZLIB },
                { "gzip", TL_LAYER_GZIP },
            },
        },
        {
            .match = ".data",
            .optional = true,
            .offset = offsetof(tl_layer_t, data.gids),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".data",
            .optional = true,
            .offset = offsetof(tl_layer_t, data.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".encoding",
            .default_json = "\"csv\"",
            .offset = offsetof(tl_layer_t, encoding),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "csv", TL_LAYER_CSV },
                { "base64", TL_LAYER_BASE64 },
            },
        },
        {
            .match = ".draworder",
            .optional = true,
            .offset = offsetof(tl_layer_t, draworder),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "topdown", TL_LAYER_TOPDOWN },
                { "index", TL_LAYER_INDEX },
            },
        },
        {
            .match = ".objects",
            .optional = true,
            .offset = offsetof(tl_layer_t, objects.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_OBJECT_TYPE_DESC,
        },
        {
            .match = ".objects",
            .optional = true,
            .offset = offsetof(tl_layer_t, objects.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".transparentcolor",
            .optional = true,
            .offset = offsetof(tl_layer_t, transparentcolor),
            .type = &TL_COLOR_STR_TYPE_DESC,
        },
        {
            .match = ".image",
            .optional = true,
            .offset = offsetof(tl_layer_t, image),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".layers",
            .optional = true,
            .offset = offsetof(tl_layer_t, layers.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_LAYER_TYPE_DESC,
        },
        {
            .match = ".layers",
            .optional = true,
            .offset = offsetof(tl_layer_t, layers.len),
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
        for (usize_t i = 0; i < self->chunks.len; i++)
            tl_chunk_dispose(&self->chunks.data[i]);
        my_free(self->chunks.data);
        my_free(self->data.gids);
        break;
    case TL_LAYER_OBJECTGROUP:
        for (usize_t i = 0; i < self->objects.len; i++)
            tl_object_dispose(&self->objects.data[i]);
        my_free(self->objects.data);
        break;
    case TL_LAYER_IMAGELAYER:
        my_free(self->image);
        break;
    case TL_LAYER_GROUP:
        for (usize_t i = 0; i < self->layers.len; i++)
            tl_layer_dispose(&self->layers.data[i]);
        my_free(self->layers.data);
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
