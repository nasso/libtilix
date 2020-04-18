/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Chunk parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/chunk.h"

const jzon_type_desc_t TL_CHUNK_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(tl_chunk_t),
    .fields = {
        {
            .match = ".data",
            .offset = offsetof(tl_chunk_t, data.gids),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .params.item_type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".data",
            .offset = offsetof(tl_chunk_t, data.len),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
        {
            .match = ".height",
            .offset = offsetof(tl_chunk_t, height),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".width",
            .offset = offsetof(tl_chunk_t, width),
            .type = &JZON_U64_TYPE_DESC,
        },
        {
            .match = ".x",
            .offset = offsetof(tl_chunk_t, x),
            .type = &JZON_I64_TYPE_DESC,
        },
        {
            .match = ".y",
            .offset = offsetof(tl_chunk_t, y),
            .type = &JZON_I64_TYPE_DESC,
        },
    },
};

void tl_chunk_dispose(const tl_chunk_t *chunk)
{
    my_free(chunk->data.gids);
}
