/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled tileset parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/common.h"
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

static jzon_t default_grid(const jzon_t tset, const jzon_deser_params_t *params)
{
    jzon_t def = jzon_create_obj();
    f64_t tilewidth = jzon_getk_num(tset, "tilewidth");
    f64_t tileheight = jzon_getk_num(tset, "tileheight");

    (void)(params);
    if (def == NULL)
        return (NULL);
    if (jzon_setk(tset, "width", jzon_create_num(tilewidth)) ||
        jzon_setk(tset, "height", jzon_create_num(tileheight))) {
        jzon_drop(def);
        return (NULL);
    }
    return (def);
}

const jzon_type_desc_t TL_TILESET_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_tileset_t),
    .fields = {
        {
            .match = ".backgroundcolor",
            .optional = true,
            .offset = offsetof(tl_tileset_t, backgroundcolor),
            .type = &TL_COLOR_STR_TYPE_DESC,
        },
        {
            .match = ".columns",
            .optional = true,
            .offset = offsetof(tl_tileset_t, columns),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".grid",
            .optional = true,
            .default_func = &default_grid,
            .offset = offsetof(tl_tileset_t, grid),
            .type = &TL_GRID_TYPE_DESC,
        },
        {
            .match = ".image",
            .optional = true,
            .offset = offsetof(tl_tileset_t, image),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".firstgid",
            .optional = true,
            .offset = offsetof(tl_tileset_t, firstgid),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".imageheight",
            .optional = true,
            .offset = offsetof(tl_tileset_t, imageheight),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".imagewidth",
            .optional = true,
            .offset = offsetof(tl_tileset_t, imagewidth),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".name",
            .optional = true,
            .offset = offsetof(tl_tileset_t, name),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".properties",
            .optional = true,
            .offset = offsetof(tl_tileset_t, properties),
            .type = &TL_PROPERTIES_TYPE_DESC,
        },
        {
            .match = ".source",
            .optional = true,
            .offset = offsetof(tl_tileset_t, source),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".spacing",
            .optional = true,
            .offset = offsetof(tl_tileset_t, spacing),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".terrains",
            .optional = true,
            .offset = offsetof(tl_tileset_t, terrains.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_TERRAIN_TYPE_DESC,
        },
        {
            .match = ".terrains",
            .optional = true,
            .offset = offsetof(tl_tileset_t, terrains.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".tilecount",
            .optional = true,
            .offset = offsetof(tl_tileset_t, tilecount),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".tiledversion",
            .optional = true,
            .offset = offsetof(tl_tileset_t, tiledversion),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".tileheight",
            .optional = true,
            .offset = offsetof(tl_tileset_t, tileheight),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".tileoffset",
            .optional = true,
            .offset = offsetof(tl_tileset_t, tileoffset),
            .type = &TL_TILEOFFSET_TYPE_DESC,
        },
        {
            .match = ".tiles",
            .optional = true,
            .offset = offsetof(tl_tileset_t, tiles.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_TILE_TYPE_DESC,
        },
        {
            .match = ".tiles",
            .optional = true,
            .offset = offsetof(tl_tileset_t, tiles.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".tilewidth",
            .optional = true,
            .offset = offsetof(tl_tileset_t, tilewidth),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".transparentcolor",
            .optional = true,
            .offset = offsetof(tl_tileset_t, transparentcolor),
            .type = &TL_COLOR_STR_TYPE_DESC,
        },
        {
            .match = ".wangsets",
            .optional = true,
            .offset = offsetof(tl_tileset_t, wangsets.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_WANGSET_TYPE_DESC,
        },
        {
            .match = ".wangsets",
            .optional = true,
            .offset = offsetof(tl_tileset_t, wangsets.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
    },
};

void tl_tileset_deinit(tl_tileset_t *self)
{
    my_free(self->image);
    my_free(self->name);
    for (usize_t i = 0; i < self->properties.len; i++)
        tl_property_deinit(&self->properties.data[i]);
    my_free(self->properties.data);
    my_free(self->source);
    for (usize_t i = 0; i < self->terrains.len; i++)
        tl_terrain_deinit(&self->terrains.data[i]);
    my_free(self->terrains.data);
    my_free(self->tiledversion);
    for (usize_t i = 0; i < self->tiles.len; i++)
        tl_tile_deinit(&self->tiles.data[i]);
    my_free(self->tiles.data);
    for (usize_t i = 0; i < self->wangsets.len; i++)
        tl_wangset_deinit(&self->wangsets.data[i]);
    my_free(self->wangsets.data);
}
