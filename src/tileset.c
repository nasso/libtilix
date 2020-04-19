/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled tileset parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/property.h"
#include "tilix/layer.h"
#include "tilix/tileset.h"

const jzon_type_desc_t TL_GRID_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_grid_t),
    .fields = {
        {
            .match = ".height",
            .offset = offsetof(tl_grid_t, height),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".orientation",
            .default_json = "\"orthogonal\"",
            .type = &JZON_ENUM_TYPE_DESC,
            .params.str_enum = {
                { "orthogonal", TL_GRID_ORTH },
                { "isometric", TL_GRID_ISO },
            },
        },
        {
            .match = ".width",
            .offset = offsetof(tl_grid_t, width),
            .type = &JZON_U64_TYPE_DESC,
        },
    },
};

const jzon_type_desc_t TL_TILEOFFSET_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_tileoffset_t),
    .fields = {
        {
            .match = ".x",
            .offset = offsetof(tl_tileoffset_t, x),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".y",
            .offset = offsetof(tl_tileoffset_t, y),
            .type = &JZON_I64_TYPE_DESC,
        },
    },
};

const jzon_type_desc_t TL_FRAME_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_frame_t),
    .fields = {
        {
            .match = ".duration",
            .offset = offsetof(tl_frame_t, duration),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".tileid",
            .offset = offsetof(tl_frame_t, tileid),
            .type = &JZON_U64_TYPE_DESC,
        },
    },
};

const jzon_type_desc_t TL_TERRAIN_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_terrain_t),
    .fields = {
        {
            .match = ".name",
            .offset = offsetof(tl_terrain_t, name),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".properties",
            .default_json = "[]",
            .offset = offsetof(tl_terrain_t, properties),
            .type = &TL_PROPERTIES_TYPE_DESC,
        },
        {
            .match = ".tile",
            .offset = offsetof(tl_terrain_t, tile),
            .type = &JZON_U64_TYPE_DESC,
        },
    },
};

void tl_terrain_deinit(tl_terrain_t *self)
{
    my_free(self->name);
    for (usize_t i = 0; i < self->properties.len; i++)
        tl_property_deinit(&self->properties.data[i]);
    my_free(self->properties.data);
}

const jzon_type_desc_t TL_TILE_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_tile_t),
    .fields = {
        {
            .match = ".animation",
            .optional = true,
            .offset = offsetof(tl_tile_t, animation.frames),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_FRAME_TYPE_DESC,
        },
        {
            .match = ".animation",
            .default_json = "[]",
            .offset = offsetof(tl_tile_t, animation.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".id",
            .offset = offsetof(tl_tile_t, id),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".image",
            .optional = true,
            .offset = offsetof(tl_tile_t, image),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".imageheight",
            .optional = true,
            .offset = offsetof(tl_tile_t, imageheight),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".imagewidth",
            .optional = true,
            .offset = offsetof(tl_tile_t, imagewidth),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".objectgroup",
            .optional = true,
            .offset = offsetof(tl_tile_t, objectgroup.v),
            .type = &TL_LAYER_TYPE_DESC,
        },
        {
            .match = ".objectgroup",
            .offset = offsetof(tl_tile_t, objectgroup.is_some),
            .type = &JZON_IS_SOME_TYPE_DESC,
        },
        {
            .match = ".probability",
            .default_json = "1.0",
            .offset = offsetof(tl_tile_t, probability),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".properties",
            .default_json = "[]",
            .offset = offsetof(tl_tile_t, properties),
            .type = &TL_PROPERTIES_TYPE_DESC,
        },
        {
            .match = ".terrain",
            .optional = true,
            .offset = offsetof(tl_tile_t, terrain.v),
            .type = &TL_TERRAIN_TYPE_DESC,
        },
        {
            .match = ".terrain",
            .offset = offsetof(tl_tile_t, terrain.is_some),
            .type = &JZON_IS_SOME_TYPE_DESC,
        },
        {
            .match = ".type",
            .offset = offsetof(tl_tile_t, type),
            .type = &JZON_STR_TYPE_DESC,
        },
    },
};

void tl_tile_deinit(tl_tile_t *self)
{
    my_free(self->animation.frames);
    my_free(self->image);
    for (usize_t i = 0; i < self->properties.len; i++)
        tl_property_deinit(&self->properties.data[i]);
    my_free(self->properties.data);
    my_free(self->type);
}
