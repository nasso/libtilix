/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Map parser tests
*/

#include <criterion/criterion.h>
#include "my/mem.h"
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/map.h"

static const char *EXAMPLE =
    "{"
    "  \"backgroundcolor\":\"#656667\","
    "  \"height\":4,"
    "  \"layers\":[ ],"
    "  \"nextobjectid\":1,"
    "  \"orientation\":\"orthogonal\","
    "  \"properties\":["
    "    {"
    "      \"name\":\"mapProperty1\","
    "      \"type\":\"string\","
    "      \"value\":\"one\""
    "    },"
    "    {"
    "      \"name\":\"mapProperty2\","
    "      \"type\":\"string\","
    "      \"value\":\"two\""
    "    }],"
    "  \"renderorder\":\"right-down\","
    "  \"tileheight\":32,"
    "  \"tilesets\":[ ],"
    "  \"tilewidth\":32,"
    "  \"version\":1,"
    "  \"tiledversion\":\"1.0.3\","
    "  \"width\":4"
    "}";

Test(map, example_parses)
{
    tl_map_t map;

    my_memset(&map, 0, sizeof(map));
    cr_assert_not(jzon_deser_cstr(EXAMPLE, &TL_MAP_TYPE_DESC, NULL, &map));
}

Test(map, example)
{
    tl_map_t map;

    my_memset(&map, 0, sizeof(map));
    jzon_deser_cstr(EXAMPLE, &TL_MAP_TYPE_DESC, NULL, &map);
    cr_assert_eq(map.backgroundcolor, 0xFF656667);
    cr_assert_eq(map.height, 4);
    cr_assert_eq(map.layers.len, 0);
    cr_assert_eq(map.nextobjectid, 1);
    cr_assert_eq(map.orientation, TL_MAP_ORTH);
    cr_assert_eq(map.renderorder, TL_MAP_RIGHT_DOWN);
    cr_assert_str_eq(map.tiledversion, "1.0.3");
    cr_assert_eq(map.tileheight, 32);
    cr_assert_eq(map.tilesets.len, 0);
    cr_assert_eq(map.tilewidth, 32);
    cr_assert_eq(map.width, 4);
}

Test(map, example_properties)
{
    tl_map_t map;

    my_memset(&map, 0, sizeof(map));
    jzon_deser_cstr(EXAMPLE, &TL_MAP_TYPE_DESC, NULL, &map);
    cr_assert_eq(map.properties.len, 2);
    cr_assert_str_eq(map.properties.data[0].name, "mapProperty1");
    cr_assert_eq(map.properties.data[0].type, TL_STRING);
    cr_assert_str_eq(map.properties.data[0].u.str, "one");
    cr_assert_str_eq(map.properties.data[1].name, "mapProperty2");
    cr_assert_eq(map.properties.data[1].type, TL_STRING);
    cr_assert_str_eq(map.properties.data[1].u.str, "two");
}

Test(map, example_defaults)
{
    tl_map_t map;

    my_memset(&map, 0, sizeof(map));
    jzon_deser_cstr(EXAMPLE, &TL_MAP_TYPE_DESC, NULL, &map);
    cr_assert_eq(map.hexsidelength, 0);
    cr_assert_not(map.infinite);
    cr_assert_eq(map.staggeraxis, TL_MAP_STAG_Y);
    cr_assert_eq(map.staggerindex, TL_MAP_STAG_ODD);
}
