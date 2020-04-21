/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Terrain parser tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/tilix.h"

static const char *EXAMPLE =
    "["
    "  {"
    "    \"name\":\"ground\","
    "    \"tile\":0"
    "  },"
    "  {"
    "    \"name\":\"chasm\","
    "    \"tile\":12"
    "  },"
    "  {"
    "    \"name\":\"cliff\","
    "    \"tile\":36"
    "  }"
    "]";

static const jzon_type_desc_t EXAMPLE_TYPE_DESC = {
    .primitive = JZ_ARR,
    .size = sizeof(tl_terrain_t[3]),
    .fields = {
        {
            .match = "",
            .offset = 0,
            .type = &JZON_PLAIN_ARR_TYPE_DESC,
            .params.min_size = 3,
            .params.max_size = 3,
            .params.item_type = &TL_TERRAIN_TYPE_DESC,
        },
    },
};

Test(terrain, example_parses)
{
    tl_terrain_t terrain[3];

    my_memset(terrain, 0, 3 * sizeof(tl_terrain_t));
    cr_assert_not(jzon_deser_cstr(EXAMPLE, &EXAMPLE_TYPE_DESC, NULL, terrain));
}

Test(terrain, example)
{
    tl_terrain_t terrain[3];

    my_memset(terrain, 0, 3 * sizeof(tl_terrain_t));
    jzon_deser_cstr(EXAMPLE, &EXAMPLE_TYPE_DESC, NULL, terrain);
    cr_assert_str_eq(terrain[0].name, "ground");
    cr_assert_str_eq(terrain[1].name, "chasm");
    cr_assert_str_eq(terrain[2].name, "cliff");
    cr_assert_eq(terrain[0].tile, 0);
    cr_assert_eq(terrain[1].tile, 12);
    cr_assert_eq(terrain[2].tile, 36);
    cr_assert_eq(terrain[0].properties.len, 0);
    cr_assert_eq(terrain[1].properties.len, 0);
    cr_assert_eq(terrain[2].properties.len, 0);
    cr_assert_null(terrain[0].properties.data);
    cr_assert_null(terrain[1].properties.data);
    cr_assert_null(terrain[2].properties.data);
}
