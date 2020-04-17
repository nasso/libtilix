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

OPT_DEFINE(tl_layer_compression_t, tl_layer_compression)

extern const jzon_type_desc_t TL_LAYER_COMPRESSION_TYPE_DESC;

typedef enum {
    TL_LAYER_TOPDOWN,
    TL_LAYER_INDEX,
} tl_layer_draworder_t;

OPT_DEFINE(tl_layer_draworder_t, tl_layer_draworder)

extern const jzon_type_desc_t TL_LAYER_DRAWORDER_TYPE_DESC;

typedef enum {
    TL_LAYER_CSV,
    TL_LAYER_BASE64,
} tl_layer_encoding_t;

OPT_DEFINE(tl_layer_encoding_t, tl_layer_encoding)

extern const jzon_type_desc_t TL_LAYER_ENCODING_TYPE_DESC;

typedef struct tl_layer *tl_layer_t;

struct tl_layer {
    struct {
        tl_chunk_t *data;
        usize_t len;
    } chunks;
    tl_layer_compression_t compression;
    struct {
        u64_t *gids;
        usize_t len;
    } data;
    tl_layer_draworder_t draworder;
    tl_layer_encoding_t encoding;
    u64_t height;
    u64_t id;
    char *image;
    struct {
        tl_layer_t *data;
        usize_t len;
    } layers;
    char *name;
    struct {
        tl_object_t *data;
        usize_t len;
    } objects;
    f64_t offsetx;
    f64_t offsety;
    f64_t opacity;
    struct {
        tl_property_t *data;
        usize_t len;
    } properties;
    i64_t startx;
    i64_t starty;
    u32_t transparentcolor;
};

OPT_DEFINE(tl_layer_t, tl_layer)

extern const jzon_type_desc_t TL_LAYER_TYPE_DESC;

#endif /* LIBTILIX_LAYER_H */
