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

static const char *OBJECT_EXAMPLE =
    "{"
    "  \"gid\":5,"
    "  \"height\":0,"
    "  \"id\":1,"
    "  \"name\":\"villager\","
    "  \"properties\":["
    "    {"
    "      \"name\":\"hp\","
    "      \"type\":\"int\","
    "      \"value\":12"
    "    }],"
    "  \"rotation\":0,"
    "  \"type\":\"npc\","
    "  \"visible\":true,"
    "  \"width\":0,"
    "  \"x\":32,"
    "  \"y\":32"
    "}";

static const char *ELLIPSE_EXAMPLE =
    "{"
    "  \"ellipse\":true,"
    "  \"height\":152,"
    "  \"id\":13,"
    "  \"name\":\"\","
    "  \"rotation\":0,"
    "  \"type\":\"\","
    "  \"visible\":true,"
    "  \"width\":248,"
    "  \"x\":560,"
    "  \"y\":808"
    "}";

static const char *RECTANGLE_EXAMPLE =
    "{"
    "  \"height\":184,"
    "  \"id\":14,"
    "  \"name\":\"\","
    "  \"rotation\":0,"
    "  \"type\":\"\","
    "  \"visible\":true,"
    "  \"width\":368,"
    "  \"x\":576,"
    "  \"y\":584"
    "}";

static const char *POINT_EXAMPLE =
    "{"
    "  \"point\":true,"
    "  \"height\":0,"
    "  \"id\":20,"
    "  \"name\":\"\","
    "  \"rotation\":0,"
    "  \"type\":\"\","
    "  \"visible\":true,"
    "  \"width\":0,"
    "  \"x\":220,"
    "  \"y\":350"
    "}";

static const char *POLYGON_EXAMPLE =
    "{"
    "  \"height\":0,"
    "  \"id\":15,"
    "  \"name\":\"\","
    "  \"polygon\":["
    "  {"
    "    \"x\":0,"
    "    \"y\":0"
    "  },"
    "  {"
    "    \"x\":152,"
    "    \"y\":88"
    "  },"
    "  {"
    "    \"x\":136,"
    "    \"y\":-128"
    "  },"
    "  {"
    "    \"x\":80,"
    "    \"y\":-280"
    "  },"
    "  {"
    "    \"x\":16,"
    "    \"y\":-288"
    "  }],"
    "  \"rotation\":0,"
    "  \"type\":\"\","
    "  \"visible\":true,"
    "  \"width\":0,"
    "  \"x\":-176,"
    "  \"y\":432"
    "}";

static const tl_point_t POLYGON_EXAMPLE_DATA[5] = {
    { .x = 0, .y = 0 },
    { .x = 152, .y = 88 },
    { .x = 136, .y = -128 },
    { .x = 80, .y = -280 },
    { .x = 16, .y = -288 },
};

static const char *POLYLINE_EXAMPLE =
    "{"
    "  \"height\":0,"
    "  \"id\":16,"
    "  \"name\":\"\","
    "  \"polyline\":["
    "  {"
    "    \"x\":0,"
    "    \"y\":0"
    "  },"
    "  {"
    "    \"x\":248,"
    "    \"y\":-32"
    "  },"
    "  {"
    "    \"x\":376,"
    "    \"y\":72"
    "  },"
    "  {"
    "    \"x\":544,"
    "    \"y\":288"
    "  },"
    "  {"
    "    \"x\":656,"
    "    \"y\":120"
    "  },"
    "  {"
    "    \"x\":512,"
    "    \"y\":0"
    "  }],"
    "  \"rotation\":0,"
    "  \"type\":\"\","
    "  \"visible\":true,"
    "  \"width\":0,"
    "  \"x\":240,"
    "  \"y\":88"
    "}";

static const tl_point_t POLYLINE_EXAMPLE_DATA[6] = {
    { .x = 0, .y = 0 },
    { .x = 248, .y = -32 },
    { .x = 376, .y = 72 },
    { .x = 544, .y = 288 },
    { .x = 656, .y = 120 },
    { .x = 512, .y = 0 },
};

static const char *TEXT_EXAMPLE =
    "{"
    "  \"height\":19,"
    "  \"id\":15,"
    "  \"name\":\"\","
    "  \"text\":"
    "  {"
    "    \"text\":\"Hello World\","
    "    \"wrap\":true"
    "  },"
    "  \"rotation\":0,"
    "  \"type\":\"\","
    "  \"visible\":true,"
    "  \"width\":248,"
    "  \"x\":48,"
    "  \"y\":136"
    "}";

Test(object, parses)
{
    tl_object_t obj;

    cr_assert_not(jzon_deser_cstr(OBJECT_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL,
        &obj));
    cr_assert_not(jzon_deser_cstr(ELLIPSE_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL,
        &obj));
    cr_assert_not(jzon_deser_cstr(RECTANGLE_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL,
        &obj));
    cr_assert_not(jzon_deser_cstr(POINT_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL,
        &obj));
    cr_assert_not(jzon_deser_cstr(POLYGON_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL,
        &obj));
    cr_assert_not(jzon_deser_cstr(POLYLINE_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL,
        &obj));
    cr_assert_not(jzon_deser_cstr(TEXT_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL,
        &obj));
}

Test(object, object_example)
{
    tl_object_t obj;

    jzon_deser_cstr(OBJECT_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL, &obj);
    cr_assert_eq(obj.kind, TL_OBJ_TILE);
    cr_assert_eq(obj.gid, 5);
    cr_assert_float_eq(obj.height, 0, EPSILON);
    cr_assert_eq(obj.id, 1);
    cr_assert_str_eq(obj.name, "villager");
    cr_assert_eq(obj.properties.len, 1);
    cr_assert_str_eq(obj.properties.data[0].name, "hp");
    cr_assert_eq(obj.properties.data[0].type, TL_INT);
    cr_assert_eq(obj.properties.data[0].u.i, 12);
    cr_assert_float_eq(obj.rotation, 0, EPSILON);
    cr_assert_str_eq(obj.type, "npc");
    cr_assert(obj.visible);
    cr_assert_float_eq(obj.width, 0, EPSILON);
    cr_assert_float_eq(obj.x, 32, EPSILON);
    cr_assert_float_eq(obj.y, 32, EPSILON);
}

Test(object, ellipse_example)
{
    tl_object_t obj;

    jzon_deser_cstr(ELLIPSE_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL, &obj);
    cr_assert_eq(obj.kind, TL_OBJ_ELLIPSE);
    cr_assert_float_eq(obj.height, 152, EPSILON);
    cr_assert_eq(obj.id, 13);
    cr_assert_str_eq(obj.name, "");
    cr_assert_float_eq(obj.rotation, 0, EPSILON);
    cr_assert_str_eq(obj.type, "");
    cr_assert(obj.visible);
    cr_assert_float_eq(obj.width, 248, EPSILON);
    cr_assert_float_eq(obj.x, 560, EPSILON);
    cr_assert_float_eq(obj.y, 808, EPSILON);
}

Test(object, rectangle_example)
{
    tl_object_t obj;

    jzon_deser_cstr(RECTANGLE_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL, &obj);
    cr_assert_eq(obj.kind, TL_OBJ_RECT);
    cr_assert_float_eq(obj.height, 184, EPSILON);
    cr_assert_eq(obj.id, 14);
    cr_assert_str_eq(obj.name, "");
    cr_assert_float_eq(obj.rotation, 0, EPSILON);
    cr_assert_str_eq(obj.type, "");
    cr_assert(obj.visible);
    cr_assert_float_eq(obj.width, 368, EPSILON);
    cr_assert_float_eq(obj.x, 576, EPSILON);
    cr_assert_float_eq(obj.y, 584, EPSILON);
}

Test(object, point_example)
{
    tl_object_t obj;

    jzon_deser_cstr(POINT_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL, &obj);
    cr_assert_eq(obj.kind, TL_OBJ_POINT);
    cr_assert_float_eq(obj.height, 0, EPSILON);
    cr_assert_eq(obj.id, 20);
    cr_assert_str_eq(obj.name, "");
    cr_assert_float_eq(obj.rotation, 0, EPSILON);
    cr_assert_str_eq(obj.type, "");
    cr_assert(obj.visible);
    cr_assert_float_eq(obj.width, 0, EPSILON);
    cr_assert_float_eq(obj.x, 220, EPSILON);
    cr_assert_float_eq(obj.y, 350, EPSILON);
}

Test(object, polygon_example)
{
    tl_object_t obj;

    jzon_deser_cstr(POLYGON_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL, &obj);
    cr_assert_eq(obj.kind, TL_OBJ_POLYGON);
    cr_assert_float_eq(obj.height, 0, EPSILON);
    cr_assert_eq(obj.id, 15);
    cr_assert_str_eq(obj.name, "");
    cr_assert_eq(obj.polygon.len, 5);
    cr_assert_arr_eq(obj.polygon.data, POLYGON_EXAMPLE_DATA,
        sizeof(tl_point_t) * 5);
    cr_assert_float_eq(obj.rotation, 0, EPSILON);
    cr_assert_str_eq(obj.type, "");
    cr_assert(obj.visible);
    cr_assert_float_eq(obj.width, 0, EPSILON);
    cr_assert_float_eq(obj.x, -176, EPSILON);
    cr_assert_float_eq(obj.y, 432, EPSILON);
}

Test(object, polyline_example)
{
    tl_object_t obj;

    jzon_deser_cstr(POLYLINE_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL, &obj);
    cr_assert_eq(obj.kind, TL_OBJ_POLYLINE);
    cr_assert_float_eq(obj.height, 0, EPSILON);
    cr_assert_eq(obj.id, 16);
    cr_assert_str_eq(obj.name, "");
    cr_assert_eq(obj.polyline.len, 6);
    cr_assert_arr_eq(obj.polyline.data, POLYLINE_EXAMPLE_DATA,
        sizeof(tl_point_t) * 6);
    cr_assert_float_eq(obj.rotation, 0, EPSILON);
    cr_assert_str_eq(obj.type, "");
    cr_assert(obj.visible);
    cr_assert_float_eq(obj.width, 0, EPSILON);
    cr_assert_float_eq(obj.x, 240, EPSILON);
    cr_assert_float_eq(obj.y, 88, EPSILON);
}

Test(object, text_example)
{
    tl_object_t obj;

    jzon_deser_cstr(TEXT_EXAMPLE, &TL_OBJECT_TYPE_DESC, NULL, &obj);
    cr_assert_eq(obj.kind, TL_OBJ_TEXT);
    cr_assert_float_eq(obj.height, 19, EPSILON);
    cr_assert_eq(obj.id, 15);
    cr_assert_str_eq(obj.name, "");
    cr_assert_str_eq(obj.text.text, "Hello World");
    cr_assert(obj.text.wrap);
    cr_assert(obj.text.kerning);
    cr_assert_float_eq(obj.rotation, 0, EPSILON);
    cr_assert_str_eq(obj.type, "");
    cr_assert(obj.visible);
    cr_assert_float_eq(obj.width, 248, EPSILON);
    cr_assert_float_eq(obj.x, 48, EPSILON);
    cr_assert_float_eq(obj.y, 136, EPSILON);
}
