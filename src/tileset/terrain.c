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
            .optional = true,
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
