/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled object
*/

#ifndef TILIX_OBJECT_H
#define TILIX_OBJECT_H

#include "my/types.h"
#include "jzon/deser.h"
#include "tilix/property.h"

typedef enum {
    TL_HALIGN_CENTER,
    TL_HALIGN_RIGHT,
    TL_HALIGN_JUSTIFY,
    TL_HALIGN_LEFT,
} tl_text_halign_t;

typedef enum {
    TL_VALIGN_CENTER,
    TL_VALIGN_BOTTOM,
    TL_VALIGN_TOP,
} tl_text_valign_t;

typedef struct {
    bool bold;
    u32_t color;
    char *fontfamily;
    tl_text_halign_t halign;
    bool italic;
    bool kerning;
    u64_t pixelsize;
    bool strikeout;
    char *text;
    bool underline;
    tl_text_valign_t valign;
    bool wrap;
} tl_text_t;

extern const jzon_type_desc_t TL_TEXT_TYPE_DESC;

void tl_text_deinit(tl_text_t *self);

typedef enum {
    TL_OBJ_ELLIPSE,
    TL_OBJ_POINT,
    TL_OBJ_RECT,
    TL_OBJ_POLYGON,
    TL_OBJ_POLYLINE,
    TL_OBJ_TEXT,
    TL_OBJ_TILE,
} tl_object_kind_t;

typedef struct {
    f64_t x;
    f64_t y;
} tl_point_t;

extern const jzon_type_desc_t TL_POINT_TYPE_DESC;

typedef struct {
    tl_object_kind_t kind;
    f64_t height;
    u64_t id;
    char *name;
    struct {
        tl_property_t *data;
        usize_t len;
    } properties;
    f64_t rotation;
    char *template;
    char *type;
    bool visible;
    f64_t width;
    f64_t x;
    f64_t y;
    u64_t gid;
    struct {
        tl_point_t *data;
        usize_t len;
    } polygon;
    struct {
        tl_point_t *data;
        usize_t len;
    } polyline;
    tl_text_t text;
} tl_object_t;

extern const jzon_type_desc_t TL_OBJECT_TYPE_DESC;

void tl_object_deinit(tl_object_t *self);

#endif /* TILIX_OBJECT_H */
