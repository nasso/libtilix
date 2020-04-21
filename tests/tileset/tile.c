/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tile parser tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/tilix.h"

static const char *EXAMPLE =
    "{"
    "  \"id\":0,"
    "  \"properties\":["
    "    {"
    "      \"name\":\"myProperty1\","
    "      \"type\":\"string\","
    "      \"value\":\"myProperty1_value\""
    "    }],"
    "  \"terrain\":[0, 1, 2, 3]"
    "}";

static const usize_t EXAMPLE_TERRAIN[4] = {0, 1, 2, 3};

Test(tile, example_parses)
{
    tl_tile_t tile;

    my_memset(&tile, 0, sizeof(tl_tile_t));
    cr_assert_not(jzon_deser_cstr(EXAMPLE, &TL_TILE_TYPE_DESC, NULL, &tile));
}

Test(tile, example)
{
    tl_tile_t tile;

    my_memset(&tile, 0, sizeof(tl_tile_t));
    jzon_deser_cstr(EXAMPLE, &TL_TILE_TYPE_DESC, NULL, &tile);
    cr_assert_eq(tile.animation.len, 0);
    cr_assert_eq(tile.properties.len, 1);
    cr_assert_str_eq(tile.properties.data[0].name, "myProperty1");
    cr_assert_eq(tile.properties.data[0].type, TL_STRING);
    cr_assert_str_eq(tile.properties.data[0].u.str, "myProperty1_value");
    cr_assert(tile.terrain.is_some);
    cr_assert_arr_eq(tile.terrain.v.i, EXAMPLE_TERRAIN, 4 * sizeof(usize_t));
    cr_assert_null(tile.image);
    cr_assert_not(tile.objectgroup.is_some);
}
