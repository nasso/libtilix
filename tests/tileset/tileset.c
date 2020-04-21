/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tileset parser tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/tilix.h"

static const char *EXAMPLE =
    "{"
    "  \"columns\":19,"
    "  \"firstgid\":1,"
    "  \"image\":\"..\\/image\\/fishbaddie_parts.png\","
    "  \"imageheight\":480,"
    "  \"imagewidth\":640,"
    "  \"margin\":3,"
    "  \"name\":\"\","
    "  \"properties\":["
    "    {"
    "      \"name\":\"myProperty1\","
    "      \"type\":\"string\","
    "      \"value\":\"myProperty1_value\""
    "    }],"
    "  \"spacing\":1,"
    "  \"tilecount\":266,"
    "  \"tileheight\":32,"
    "  \"tilewidth\":32"
    "}";

Test(tileset, example_parses)
{
    tl_tileset_t tset;

    my_memset(&tset, 0, sizeof(tset));
    cr_assert_not(jzon_deser_cstr(EXAMPLE, &TL_TILESET_TYPE_DESC, NULL, &tset));
}

Test(tileset, example)
{
    tl_tileset_t tset;

    my_memset(&tset, 0, sizeof(tset));
    jzon_deser_cstr(EXAMPLE, &TL_TILESET_TYPE_DESC, NULL, &tset);
    cr_assert_eq(tset.backgroundcolor, 0);
    cr_assert_eq(tset.columns, 19);
    cr_assert_eq(tset.firstgid, 1);
    cr_assert_str_eq(tset.image, "../image/fishbaddie_parts.png");
    cr_assert_eq(tset.imageheight, 480);
    cr_assert_eq(tset.imagewidth, 640);
    cr_assert_eq(tset.margin, 3);
    cr_assert_str_eq(tset.name, "");
    cr_assert_eq(tset.spacing, 1);
    cr_assert_eq(tset.tilecount, 266);
    cr_assert_eq(tset.tileheight, 32);
    cr_assert_eq(tset.tilewidth, 32);
    tl_tileset_deinit(&tset);
}

Test(tileset, example_properties)
{
    tl_tileset_t tset;

    my_memset(&tset, 0, sizeof(tset));
    jzon_deser_cstr(EXAMPLE, &TL_TILESET_TYPE_DESC, NULL, &tset);
    cr_assert_eq(tset.properties.len, 1);
    cr_assert_str_eq(tset.properties.data[0].name, "myProperty1");
    cr_assert_eq(tset.properties.data[0].type, TL_STRING);
    cr_assert_str_eq(tset.properties.data[0].u.str, "myProperty1_value");
}

Test(tileset, example_defaults)
{
    tl_tileset_t tset;

    my_memset(&tset, 0, sizeof(tset));
    jzon_deser_cstr(EXAMPLE, &TL_TILESET_TYPE_DESC, NULL, &tset);
    cr_assert_null(tset.source);
    cr_assert_eq(tset.terrains.len, 0);
    cr_assert_eq(tset.grid.width, tset.tilewidth);
    cr_assert_eq(tset.grid.height, tset.tileheight);
    cr_assert_eq(tset.grid.orientation, TL_GRID_ORTH);
    cr_assert_not(tset.transparentcolor.is_some);
    cr_assert_eq(tset.wangsets.len, 0);
}
