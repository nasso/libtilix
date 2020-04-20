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

const jzon_type_desc_t TL_WANGCOLOR_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_wangcolor_t),
    .fields = {
        {
            .match = ".color",
            .offset = offsetof(tl_wangcolor_t, color),
            .type = &TL_COLOR_STR_TYPE_DESC,
        },
        {
            .match = ".name",
            .offset = offsetof(tl_wangcolor_t, name),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".probability",
            .offset = offsetof(tl_wangcolor_t, probability),
            .type = &JZON_F64_TYPE_DESC,
        },
        {
            .match = ".tile",
            .offset = offsetof(tl_wangcolor_t, tile),
            .type = &JZON_U64_TYPE_DESC,
        },
    },
};

void tl_wangcolor_deinit(tl_wangcolor_t *self)
{
    my_free(self->name);
}

const jzon_type_desc_t TL_WANGTILE_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_wangtile_t),
    .fields = {
        {
            .match = ".dflip",
            .default_json = "false",
            .offset = offsetof(tl_wangtile_t, dflip),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".hflip",
            .default_json = "false",
            .offset = offsetof(tl_wangtile_t, hflip),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".tileid",
            .offset = offsetof(tl_wangtile_t, tileid),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".vflip",
            .default_json = "false",
            .offset = offsetof(tl_wangtile_t, vflip),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".wangid",
            .offset = offsetof(tl_wangtile_t, wangid),
            .type = &JZON_PLAIN_ARR_TYPE_DESC,
            .params.min_size = 8,
            .params.max_size = 8,
            .params.item_type = &JZON_U8_TYPE_DESC,
        },
    },
};

const jzon_type_desc_t TL_WANGSET_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_wangset_t),
    .fields = {
        {
            .match = ".cornercolors",
            .offset = offsetof(tl_wangset_t, cornercolors.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_WANGCOLOR_TYPE_DESC,
        },
        {
            .match = ".cornercolors",
            .offset = offsetof(tl_wangset_t, cornercolors.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".edgecolors",
            .offset = offsetof(tl_wangset_t, edgecolors.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_WANGCOLOR_TYPE_DESC,
        },
        {
            .match = ".edgecolors",
            .offset = offsetof(tl_wangset_t, edgecolors.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".properties",
            .default_json = "[]",
            .offset = offsetof(tl_wangset_t, properties),
            .type = &TL_PROPERTIES_TYPE_DESC,
        },
        {
            .match = ".tile",
            .offset = offsetof(tl_wangset_t, tile),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".wangtiles",
            .offset = offsetof(tl_wangset_t, wangtiles.data),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &TL_WANGTILE_TYPE_DESC,
        },
        {
            .match = ".wangtiles",
            .offset = offsetof(tl_wangset_t, wangtiles.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
    },
};

void tl_wangset_deinit(tl_wangset_t *self)
{
    for (usize_t i = 0; i < self->cornercolors.len; i++)
        tl_wangcolor_deinit(&self->cornercolors.data[i]);
    my_free(self->cornercolors.data);
    for (usize_t i = 0; i < self->edgecolors.len; i++)
        tl_wangcolor_deinit(&self->edgecolors.data[i]);
    my_free(self->edgecolors.data);
    my_free(self->name);
    for (usize_t i = 0; i < self->properties.len; i++)
        tl_property_deinit(&self->properties.data[i]);
    my_free(self->properties.data);
    my_free(self->wangtiles.data);
}
