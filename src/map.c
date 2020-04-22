/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Map parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/layer.h"
#include "tilix/tileset.h"
#include "tilix/property.h"
#include "tilix/common.h"
#include "tilix/map.h"

const jzon_type_desc_t TL_MAP_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_map_t),
    .fields = {
        {
            .match = ".backgroundcolor",
            .default_json = "\"#000000\"",
            .offset = offsetof(tl_map_t, backgroundcolor),
            .type = &TL_COLOR_STR_TYPE_DESC,
        },
        {
            .match = ".height",
            .offset = offsetof(tl_map_t, height),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".hexsidelength",
            .optional = true,
            .offset = offsetof(tl_map_t, hexsidelength),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".infinite",
            .default_json = "false",
            .offset = offsetof(tl_map_t, infinite),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".layers",
            .offset = offsetof(tl_map_t, layers.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_LAYER_TYPE_DESC,
        },
        {
            .match = ".layers",
            .offset = offsetof(tl_map_t, layers.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".nextlayerid",
            .default_json = "0",
            .offset = offsetof(tl_map_t, nextlayerid),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".nextobjectid",
            .default_json = "0",
            .offset = offsetof(tl_map_t, nextobjectid),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".orientation",
            .offset = offsetof(tl_map_t, orientation),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "orthogonal", TL_MAP_ORTH },
                { "isometric", TL_MAP_ISO },
                { "staggered", TL_MAP_STAG },
                { "hexagonal", TL_MAP_HEX },
            },
        },
        {
            .match = ".properties",
            .default_json = "[]",
            .offset = offsetof(tl_map_t, properties),
            .type = &TL_PROPERTIES_TYPE_DESC,
        },
        {
            .match = ".renderorder",
            .default_json = "\"right-down\"",
            .offset = offsetof(tl_map_t, renderorder),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "right-down", TL_MAP_RIGHT_DOWN },
                { "right-up", TL_MAP_RIGHT_UP },
                { "left-down", TL_MAP_LEFT_DOWN },
                { "left-up", TL_MAP_LEFT_UP },
            },
        },
        {
            .match = ".staggeraxis",
            .default_json = "\"y\"",
            .offset = offsetof(tl_map_t, staggeraxis),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "x", TL_MAP_STAG_X },
                { "y", TL_MAP_STAG_Y },
            },
        },
        {
            .match = ".staggerindex",
            .default_json = "\"odd\"",
            .offset = offsetof(tl_map_t, staggerindex),
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "odd", TL_MAP_STAG_ODD },
                { "even", TL_MAP_STAG_EVEN },
            },
        },
        {
            .match = ".tiledversion",
            .optional = true,
            .offset = offsetof(tl_map_t, tiledversion),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".tileheight",
            .offset = offsetof(tl_map_t, tileheight),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".tilesets",
            .optional = true,
            .offset = offsetof(tl_map_t, tilesets.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_TILESET_TYPE_DESC,
        },
        {
            .match = ".tilesets",
            .optional = true,
            .offset = offsetof(tl_map_t, tilesets.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".tilewidth",
            .offset = offsetof(tl_map_t, tilewidth),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".width",
            .offset = offsetof(tl_map_t, width),
            .type = &JZON_U64_TYPE_DESC,
        },
    },
};

bool tl_map_load(const char *path, tl_map_t *map)
{
    my_memset(map, 0, sizeof(tl_map_t));
    return (jzon_deser_path(path, &TL_MAP_TYPE_DESC, NULL, map));
}

void tl_map_deinit(tl_map_t *self)
{
    for (usize_t i = 0; i < self->layers.len; i++)
        tl_layer_deinit(&self->layers.data[i]);
    my_free(self->layers.data);
    for (usize_t i = 0; i < self->properties.len; i++)
        tl_property_deinit(&self->properties.data[i]);
    my_free(self->properties.data);
    my_free(self->tiledversion);
    for (usize_t i = 0; i < self->tilesets.len; i++)
        tl_tileset_deinit(&self->tilesets.data[i]);
    my_free(self->tilesets.data);
}
