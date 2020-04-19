/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled layer
*/

#ifndef LIBTILIX_LAYER_H
#define LIBTILIX_LAYER_H

#include "my/types.h"
#include "jzon/deser.h"
#include "tilix/object.h"
#include "tilix/property.h"
#include "tilix/chunk.h"

typedef enum {
    TL_LAYER_ZLIB,
    TL_LAYER_GZIP,
    TL_LAYER_NONE,
} tl_layer_compression_t;

typedef enum {
    TL_LAYER_TOPDOWN,
    TL_LAYER_INDEX,
} tl_layer_draworder_t;

typedef enum {
    TL_LAYER_CSV,
    TL_LAYER_BASE64,
} tl_layer_encoding_t;

typedef enum {
    TL_LAYER_TILELAYER,
    TL_LAYER_OBJECTGROUP,
    TL_LAYER_IMAGELAYER,
    TL_LAYER_GROUP,
} tl_layer_type_t;

typedef struct tl_layer tl_layer_t;

struct tl_layer {
    u64_t id;
    char *name;
    i64_t x;
    i64_t y;
    u64_t width;
    u64_t height;
    i64_t startx;
    i64_t starty;
    f64_t offsetx;
    f64_t offsety;
    f64_t opacity;
    bool visible;
    tl_layer_type_t type;
    struct {
        tl_chunk_t *data;
        usize_t len;
    } chunks;
    tl_layer_compression_t compression;
    struct {
        u64_t *gids;
        usize_t len;
    } data;
    tl_layer_encoding_t encoding;
    tl_layer_draworder_t draworder;
    struct {
        tl_object_t *data;
        usize_t len;
    } objects;
    u32_t transparentcolor;
    char *image;
    struct {
        tl_layer_t *data;
        usize_t len;
    } layers;
    struct {
        tl_property_t *data;
        usize_t len;
    } properties;
};

OPT_DEFINE(tl_layer_t, tl_layer)

extern const jzon_type_desc_t TL_LAYER_TYPE_DESC;

void tl_layer_deinit(tl_layer_t *self);

#endif /* LIBTILIX_LAYER_H */
