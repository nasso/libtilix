/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** cstrwriter implementation
*/

#include "my/my.h"
#include "my/io/cstrwriter.h"

struct string_buffer {
    char **str;
    usize_t len;
    usize_t cursor;
};

static OPT(usize) write_cb(void *ptr, const void *buffer, usize_t n)
{
    struct string_buffer *dest = ptr;
    usize_t new_strlen = dest->len + n;
    char *new_str = my_malloc((new_strlen + 1) * sizeof(char));

    if (new_str == NULL)
        return (NONE(usize));
    my_memcpy(new_str, *dest->str, dest->len * sizeof(char));
    my_memcpy(new_str + dest->len, buffer, n * sizeof(char));
    new_str[new_strlen] = '\0';
    my_free(*dest->str);
    *dest->str = new_str;
    dest->len = new_strlen;
    return (SOME(usize, n));
}

static struct string_buffer *init_buf(char **dest)
{
    struct string_buffer *buf = my_malloc(sizeof(struct string_buffer));

    if (buf == NULL)
        return (NULL);
    *dest = my_cstrdup(*dest ? *dest : "");
    buf->str = dest;
    buf->len = my_cstrlen(*dest);
    buf->cursor = 0;
    return (buf);
}

bufwriter_t *cstrwriter_new(char **dest, usize_t bufsize)
{
    bufwriter_t *bw = bufwriter_new(bufsize);

    if (bw == NULL)
        return (NULL);
    bw->user_data = init_buf(dest);
    bw->write_cb = &write_cb;
    bw->free_cb = &my_free;
    return (bw);
}
