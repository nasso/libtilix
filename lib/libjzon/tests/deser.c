/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON deserializer tests
*/

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static const char *SAMPLE_MAP =
    "{"
    "   \"name\": \"Gay Zone\","
    "   \"type\": \"map\","
    "   \"epic\": true,"
    "   \"opt_int\": 46,"
    "   \"fixed_array\": [1, 2, 3, 4],"
    "   \"layers\": ["
    "       {"
    "           \"size\": {\"width\": 4, \"height\": 2},"
    "           \"tiles\": [5, 3, 8, 4, 9, 6, 2, 7]"
    "       },"
    "       {"
    "           \"size\": {\"width\": 3, \"height\": 3},"
    "           \"tiles\": [9, 5, 3, 8, 4, 6, 2, 8, 5]"
    "       },"
    "       {"
    "           \"size\": {\"width\": 2, \"height\": 5},"
    "           \"tiles\": [7, 5, 8, 6, 3, 5, 1, 8, 2, 5]"
    "       }"
    "   ],"
    "   \"properties\": ["
    "       {\"goat\": \"baa\", \"fox\": \"yip\"},"
    "       {\"dog\": \"bark\", \"cat\": \"meow\"}"
    "   ]"
    "}";

static const u64_t TILES_1[8] = {5, 3, 8, 4, 9, 6, 2, 7};
static const u64_t TILES_2[9] = {9, 5, 3, 8, 4, 6, 2, 8, 5};
static const u64_t TILES_3[10] = {7, 5, 8, 6, 3, 5, 1, 8, 2, 5};
static const u32_t FIXED_ARRAY[4] = {1, 2, 3, 4};

enum type {
    TYPE_TILESET,
    TYPE_SOMETHING,
    TYPE_MAP,
    TYPE_TEMPLATE,
};

struct layer {
    struct {
        usize_t width;
        usize_t height;
    } size;
    u64_t *tiles;
};

struct map {
    char *name;
    char *default_is_name;
    bool epic;
    OPT(i32) opt_int;
    OPT(i32) opt_int2;
    bool true_by_default;
    enum type type;
    u32_t fixed_array[4];
    struct layer *layers;
    usize_t layer_count;
    hash_map_t **properties;
    usize_t property_count;
};

static const jzon_type_desc_t LAYER_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(struct layer),
    .is_ptr = true,
    .fields = {
        {
            .match = ".size.width",
            .offset = offsetof(struct layer, size.width),
            .type = &JZON_USIZE_TYPE_DESC,
        },
        {
            .match = ".size.height",
            .offset = offsetof(struct layer, size.height),
            .type = &JZON_USIZE_TYPE_DESC,
        },
        {
            .match = ".tiles",
            .offset = offsetof(struct layer, tiles),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &JZON_U64_TYPE_DESC,
        },
    },
};

static const jzon_type_desc_t MAP_PROPERTY_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(hash_map_t*),
    .fields = {
        {
            .match = "",
            .offset = 0,
            .type = &JZON_HASH_MAP_TYPE_DESC,
            .params.item_type = &JZON_STR_TYPE_DESC,
        },
    },
};

static jzon_t default_is_name(const jzon_t mapjz,
    const jzon_deser_params_t *params)
{
    (void)(params);
    return (jzon_create_str(jzon_getk_str(mapjz, "name")));
}


static const jzon_type_desc_t MAP_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(struct map),
    .fields = {
        {
            .match = ".name",
            .offset = offsetof(struct map, name),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".default_is_name",
            .default_func = &default_is_name,
            .offset = offsetof(struct map, default_is_name),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".epic",
            .offset = offsetof(struct map, epic),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".opt_int",
            .optional = true,
            .offset = offsetof(struct map, opt_int.v),
            .type = &JZON_I32_TYPE_DESC,
        },
        {
            .match = ".opt_int",
            .offset = offsetof(struct map, opt_int.is_some),
            .type = &JZON_IS_SOME_TYPE_DESC,
        },
        {
            .match = ".opt_int2",
            .optional = true,
            .offset = offsetof(struct map, opt_int2.v),
            .type = &JZON_I32_TYPE_DESC,
        },
        {
            .match = ".opt_int2",
            .offset = offsetof(struct map, opt_int2.is_some),
            .type = &JZON_IS_SOME_TYPE_DESC,
        },
        {
            .match = ".optional",
            .optional = true,
            .offset = offsetof(struct map, name),
            .type = &JZON_I8_TYPE_DESC,
        },
        {
            .match = ".true_by_default",
            .default_json = "true",
            .offset = offsetof(struct map, true_by_default),
            .type = &JZON_BOOL_TYPE_DESC,
        },
        {
            .match = ".type",
            .offset = offsetof(struct map, type),
            .type = &JZON_ENUM_TYPE_DESC,
            .optional = true,
            .params.str_enum = {
                { "tileset", TYPE_TILESET },
                { "something", TYPE_SOMETHING },
                { "map", TYPE_MAP },
                { "template", TYPE_TEMPLATE },
            },
        },
        {
            .match = ".type",
            .offset = offsetof(struct map, type),
            .type = &JZON_I32_TYPE_DESC,
            .optional = true,
        },
        {
            .match = ".fixed_array",
            .offset = offsetof(struct map, fixed_array),
            .type = &JZON_PLAIN_ARR_TYPE_DESC,
            .params.max_size = 4,
            .params.min_size = 4,
            .params.item_type = &JZON_U32_TYPE_DESC,
        },
        {
            .match = ".layers",
            .offset = offsetof(struct map, layers),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &LAYER_TYPE_DESC,
        },
        {
            .match = ".layers",
            .offset = offsetof(struct map, layer_count),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".properties",
            .offset = offsetof(struct map, properties),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &MAP_PROPERTY_TYPE_DESC,
        },
        {
            .match = ".properties",
            .offset = offsetof(struct map, property_count),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
    },
};

Test(deser, map)
{
    struct map map = {0};

    cr_assert_not(jzon_deser_cstr(SAMPLE_MAP, &MAP_TYPE_DESC, NULL, &map));
    cr_assert_str_eq(map.name, "Gay Zone");
    cr_assert_str_eq(map.default_is_name, "Gay Zone");
    cr_assert(map.epic);
    cr_assert(map.true_by_default);
    cr_assert(map.opt_int.is_some);
    cr_assert_eq(map.opt_int.v, 46);
    cr_assert_not(map.opt_int2.is_some);
    cr_assert_eq(map.type, TYPE_MAP);
}

Test(deser, plain_array)
{
    struct map map = {0};

    jzon_deser_cstr(SAMPLE_MAP, &MAP_TYPE_DESC, NULL, &map);
    cr_assert_arr_eq(map.fixed_array, FIXED_ARRAY, 4 * sizeof(u32_t));
}

Test(deser, heap_array_simple)
{
    struct map map = {0};

    jzon_deser_cstr(SAMPLE_MAP, &MAP_TYPE_DESC, NULL, &map);
    cr_assert_eq(map.layer_count, 3);
    cr_assert_eq(map.layers[0].size.width, 4);
    cr_assert_eq(map.layers[0].size.height, 2);
    cr_assert_arr_eq(map.layers[0].tiles, TILES_1, 8 * sizeof(u64_t));
    cr_assert_eq(map.layers[1].size.width, 3);
    cr_assert_eq(map.layers[1].size.height, 3);
    cr_assert_arr_eq(map.layers[1].tiles, TILES_2, 9 * sizeof(u64_t));
    cr_assert_eq(map.layers[2].size.width, 2);
    cr_assert_eq(map.layers[2].size.height, 5);
    cr_assert_arr_eq(map.layers[2].tiles, TILES_3, 10 * sizeof(u64_t));
}

Test(deser, heap_array_complex)
{
    struct map map = {0};

    jzon_deser_cstr(SAMPLE_MAP, &MAP_TYPE_DESC, NULL, &map);
    cr_assert_eq(map.property_count, 2);
    cr_assert_not_null(map.properties[0]);
    cr_assert(hash_map_contains_key(map.properties[0], "goat"));
    cr_assert(hash_map_contains_key(map.properties[0], "fox"));
    cr_assert_str_eq(hash_map_get(map.properties[0], "goat").v, "baa");
    cr_assert_str_eq(hash_map_get(map.properties[0], "fox").v, "yip");
    cr_assert_not_null(map.properties[1]);
    cr_assert(hash_map_contains_key(map.properties[1], "dog"));
    cr_assert(hash_map_contains_key(map.properties[1], "cat"));
    cr_assert_str_eq(hash_map_get(map.properties[1], "dog").v, "bark");
    cr_assert_str_eq(hash_map_get(map.properties[1], "cat").v, "meow");
}
