/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled Map
*/

#ifndef LIBTILIX_MAP_H
#define LIBTILIX_MAP_H

#include "my/types.h"
#include "jzon/deser.h"
#include "tilix/layer.h"
#include "tilix/tileset.h"
#include "tilix/property.h"

typedef enum {
    TL_MAP_ORTH,
    TL_MAP_ISO,
    TL_MAP_STAG,
    TL_MAP_HEX,
} tl_map_orient_t;

typedef enum {
    TL_MAP_RIGHT_DOWN,
    TL_MAP_RIGHT_UP,
    TL_MAP_LEFT_DOWN,
    TL_MAP_LEFT_UP,
} tl_map_renderorder_t;

typedef enum {
    TL_MAP_STAG_X,
    TL_MAP_STAG_Y,
} tl_map_staggeraxis_t;

typedef enum {
    TL_MAP_STAG_ODD,
    TL_MAP_STAG_EVEN,
} tl_map_staggerindex_t;

typedef struct {
    u32_t backgroundcolor;
    u64_t height;
    i64_t hexsidelength;
    bool infinite;
    struct {
        tl_layer_t *data;
        usize_t len;
    } layers;
    i64_t nextlayerid;
    i64_t nextobjectid;
    tl_map_orient_t orientation;
    struct {
        tl_property_t *data;
        usize_t len;
    } properties;
    tl_map_renderorder_t renderorder;
    tl_map_staggeraxis_t staggeraxis;
    tl_map_staggerindex_t staggerindex;
    char *tiledversion;
    u64_t tileheight;
    struct {
        tl_tileset_t *data;
        usize_t len;
    } tilesets;
    u64_t tilewidth;
    u64_t width;
} tl_map_t;

OPT_DEFINE(tl_map_t, tl_map)

extern const jzon_type_desc_t TL_MAP_TYPE_DESC;

void tl_map_deinit(tl_map_t *self);

#endif /* LIBTILIX_MAP_H */
