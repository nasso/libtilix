/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled tileset
*/

#ifndef LIBTILIX_TILESET_H
#define LIBTILIX_TILESET_H

#include "my/types.h"
#include "jzon/deser.h"
#include "tilix/property.h"
#include "tilix/layer.h"

typedef enum {
    TL_GRID_ORTH,
    TL_GRID_ISO,
} tl_grid_orientation_t;

typedef struct {
    u64_t height;
    tl_grid_orientation_t orientation;
    u64_t width;
} tl_grid_t;

extern const jzon_type_desc_t TL_GRID_TYPE_DESC;

typedef struct {
    i64_t x;
    i64_t y;
} tl_tileoffset_t;

extern const jzon_type_desc_t TL_TILEOFFSET_TYPE_DESC;

typedef struct {
    u64_t duration;
    u64_t tileid;
} tl_frame_t;

extern const jzon_type_desc_t TL_FRAME_TYPE_DESC;

typedef struct {
    char *name;
    struct {
        tl_property_t *data;
        usize_t len;
    } properties;
    u64_t tile;
} tl_terrain_t;

extern const jzon_type_desc_t TL_TERRAIN_TYPE_DESC;

void tl_terrain_deinit(tl_terrain_t *self);

typedef struct {
    usize_t i[4];
} tl_tile_terrain_t;

OPT_DEFINE(tl_tile_terrain_t, tl_tile_terrain)

typedef struct {
    struct {
        tl_frame_t *frames;
        usize_t len;
    } animation;
    u64_t id;
    char *image;
    u64_t imageheight;
    u64_t imagewidth;
    OPT(tl_layer) objectgroup;
    f64_t probability;
    struct {
        tl_property_t *data;
        usize_t len;
    } properties;
    OPT(tl_tile_terrain) terrain;
    char *type;
} tl_tile_t;

extern const jzon_type_desc_t TL_TILE_TYPE_DESC;

void tl_tile_deinit(tl_tile_t *self);

typedef struct {
    u32_t color;
    char *name;
    f64_t probability;
    u64_t tile;
} tl_wangcolor_t;

extern const jzon_type_desc_t TL_WANGCOLOR_TYPE_DESC;

void tl_wangcolor_deinit(tl_wangcolor_t *self);

typedef struct {
    bool dflip;
    bool hflip;
    u64_t tileid;
    bool vflip;
    u8_t wangid[8];
} tl_wangtile_t;

extern const jzon_type_desc_t TL_WANGTILE_TYPE_DESC;

typedef struct {
    struct {
        tl_wangcolor_t *data;
        usize_t len;
    } cornercolors;
    struct {
        tl_wangcolor_t *data;
        usize_t len;
    } edgecolors;
    char *name;
    struct {
        tl_property_t *data;
        usize_t len;
    } properties;
    u64_t tile;
    struct {
        tl_wangtile_t *data;
        usize_t len;
    } wangtiles;
} tl_wangset_t;

extern const jzon_type_desc_t TL_WANGSET_TYPE_DESC;

void tl_wangset_deinit(tl_wangset_t *self);

typedef struct {
    u32_t backgroundcolor;
    u64_t columns;
    u64_t firstgid;
    tl_grid_t grid;
    char *image;
    u64_t imageheight;
    u64_t imagewidth;
    u64_t margin;
    char *name;
    struct {
        tl_property_t *data;
        usize_t len;
    } properties;
    char *source;
    u64_t spacing;
    struct {
        tl_terrain_t *data;
        usize_t len;
    } terrains;
    u64_t tilecount;
    char *tiledversion;
    u64_t tileheight;
    tl_tileoffset_t tileoffset;
    struct {
        tl_tile_t *data;
        usize_t len;
    } tiles;
    u64_t tilewidth;
    u32_t transparentcolor;
    struct {
        tl_wangset_t *data;
        usize_t len;
    } wangsets;
} tl_tileset_t;

OPT_DEFINE(tl_tileset_t, tl_tileset)

extern const jzon_type_desc_t TL_TILESET_TYPE_DESC;

void tl_tileset_deinit(tl_tileset_t *self);

#endif /* LIBTILIX_TILESET_H */
