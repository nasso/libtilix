/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled chunk
*/

#ifndef LIBTILIX_CHUNK_H
#define LIBTILIX_CHUNK_H

#include "my/types.h"
#include "jzon/deser.h"

typedef struct {
    struct {
        u64_t *gids;
        usize_t len;
    } data;
    u64_t height;
    u64_t width;
    i64_t x;
    i64_t y;
} tl_chunk_t;

OPT_DEFINE(tl_chunk_t, tl_chunk)

extern const jzon_type_desc_t TL_CHUNK_TYPE_DESC;

#endif /* LIBTILIX_CHUNK_H */
