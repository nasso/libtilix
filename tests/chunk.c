/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Chunk parser tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/chunk.h"

static const u64_t EXAMPLE_DATA[16] = {1, 2, 1, 2, 3, 1, 3, 1, 2, 2, 3, 3, 4, 4,
    4, 1};
static const char *EXAMPLE =
    "{"
    "  \"data\":[1, 2, 1, 2, 3, 1, 3, 1, 2, 2, 3, 3, 4, 4, 4, 1],"
    "  \"height\":16,"
    "  \"width\":16,"
    "  \"x\":0,"
    "  \"y\":-16"
    "}";

Test(chunk, example)
{
    tl_chunk_t chunk;

    cr_assert_not(jzon_deser_cstr(EXAMPLE, &TL_CHUNK_TYPE_DESC, NULL, &chunk));
    cr_assert_eq(chunk.data.len, 16);
    cr_assert_arr_eq(chunk.data.gids, EXAMPLE_DATA, 16);
    cr_assert_eq(chunk.height, 16);
    cr_assert_eq(chunk.width, 16);
    cr_assert_eq(chunk.x, 0);
    cr_assert_eq(chunk.y, -16);
    tl_chunk_dispose(&chunk);
}
