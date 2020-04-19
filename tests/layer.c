/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Object parser tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/tilix.h"

static const f64_t EPSILON = 0.000001;

static const char *TILE_LAYER_EXAMPLE =
    "{"
    "  \"id\":18,"
    "  \"data\":[1, 2, 1, 2, 3, 1, 3, 1, 2, 2, 3, 3, 4, 4, 4, 1],"
    "  \"height\":4,"
    "  \"name\":\"ground\","
    "  \"opacity\":1,"
    "  \"properties\":["
    "    {"
    "      \"name\":\"tileLayerProp\","
    "      \"type\":\"int\","
    "      \"value\":1"
    "    }],"
    "  \"type\":\"tilelayer\","
    "  \"visible\":true,"
    "  \"width\":4,"
    "  \"x\":0,"
    "  \"y\":0"
    "}";

static const u64_t TILE_LAYER_EXAMPLE_DATA[16] = {1, 2, 1, 2, 3, 1, 3, 1, 2,
    2, 3, 3, 4, 4, 4, 1};

static const char *OBJECT_LAYER_EXAMPLE =
    "{"
    "  \"id\":47,"
    "  \"draworder\":\"topdown\","
    "  \"height\":0,"
    "  \"name\":\"people\","
    "  \"objects\":[ ],"
    "  \"opacity\":1,"
    "  \"properties\":["
    "    {"
    "      \"name\":\"layerProp1\","
    "      \"type\":\"string\","
    "      \"value\":\"someStringValue\""
    "    }],"
    "  \"type\":\"objectgroup\","
    "  \"visible\":true,"
    "  \"width\":0,"
    "  \"x\":0,"
    "  \"y\":0"
    "}";

Test(layer, parses)
{
    tl_layer_t layer;

    cr_assert_not(jzon_deser_cstr(TILE_LAYER_EXAMPLE, &TL_LAYER_TYPE_DESC,
        NULL, &layer));
    cr_assert_not(jzon_deser_cstr(OBJECT_LAYER_EXAMPLE, &TL_LAYER_TYPE_DESC,
        NULL, &layer));
}

Test(layer, tile_layer_example)
{
    tl_layer_t layer;

    jzon_deser_cstr(TILE_LAYER_EXAMPLE, &TL_LAYER_TYPE_DESC, NULL, &layer);
    cr_assert_eq(layer.id, 18);
    cr_assert_eq(layer.data.len, 16);
    cr_assert_arr_eq(layer.data.gids, TILE_LAYER_EXAMPLE_DATA,
        16 * sizeof(u64_t));
    cr_assert_float_eq(layer.height, 4, EPSILON);
    cr_assert_str_eq(layer.name, "ground");
    cr_assert_float_eq(layer.opacity, 1, EPSILON);
    cr_assert_eq(layer.properties.len, 1);
    cr_assert_str_eq(layer.properties.data[0].name, "tileLayerProp");
    cr_assert_eq(layer.properties.data[0].type, TL_INT);
    cr_assert_eq(layer.properties.data[0].u.i, 1);
    cr_assert_eq(layer.type, TL_LAYER_TILELAYER);
    cr_assert(layer.visible);
    cr_assert_float_eq(layer.width, 4, EPSILON);
    cr_assert_float_eq(layer.x, 0, EPSILON);
    cr_assert_float_eq(layer.y, 0, EPSILON);
    cr_assert_eq(layer.compression, TL_LAYER_NONE);
    cr_assert_eq(layer.encoding, TL_LAYER_CSV);
    cr_assert_float_eq(layer.offsetx, 0, EPSILON);
    cr_assert_float_eq(layer.offsety, 0, EPSILON);
}

Test(layer, object_layer_example)
{
    tl_layer_t layer;

    jzon_deser_cstr(OBJECT_LAYER_EXAMPLE, &TL_LAYER_TYPE_DESC, NULL, &layer);
    cr_assert_eq(layer.id, 47);
    cr_assert_float_eq(layer.height, 0, EPSILON);
    cr_assert_str_eq(layer.name, "people");
    cr_assert_eq(layer.objects.len, 0);
    cr_assert_float_eq(layer.opacity, 1, EPSILON);
    cr_assert_eq(layer.properties.len, 1);
    cr_assert_str_eq(layer.properties.data[0].name, "layerProp1");
    cr_assert_eq(layer.properties.data[0].type, TL_STRING);
    cr_assert_str_eq(layer.properties.data[0].u.str, "someStringValue");
    cr_assert_eq(layer.type, TL_LAYER_OBJECTGROUP);
    cr_assert(layer.visible);
    cr_assert_float_eq(layer.width, 0, EPSILON);
    cr_assert_float_eq(layer.x, 0, EPSILON);
    cr_assert_float_eq(layer.y, 0, EPSILON);
    cr_assert_eq(layer.draworder, TL_LAYER_TOPDOWN);
    cr_assert_float_eq(layer.offsetx, 0, EPSILON);
    cr_assert_float_eq(layer.offsety, 0, EPSILON);
}
