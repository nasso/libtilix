/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Buffered writer
*/

#include "my/my.h"
#include "my/io.h"

bufwriter_t *bufwriter_new(usize_t buf_size)
{
    bufwriter_t *bw = my_malloc(sizeof(bufwriter_t));

    if (bw == NULL)
        return (NULL);
    bw->buffer = my_malloc(sizeof(u8_t) * buf_size);
    if (bw->buffer == NULL) {
        my_free(bw);
        return (NULL);
    }
    bw->buffer_size = buf_size;
    bw->cursor = 0;
    bw->ended = 0;
    bw->user_data = NULL;
    bw->write_cb = NULL;
    bw->free_cb = NULL;
    return (bw);
}

void bufwriter_free(bufwriter_t *bw)
{
    if (bw == NULL)
        return;
    bufwriter_flush(bw);
    if (bw->free_cb)
        bw->free_cb(bw->user_data);
    my_free(bw->buffer);
    my_free(bw);
}

OPT(usize) bufwriter_flush(bufwriter_t *bw)
{
    usize_t bytes_written = 0;

    if (bw->cursor > 0)
        bytes_written = bw->write_cb(bw->user_data, bw->buffer, bw->cursor).v;
    bw->cursor = 0;
    return (SOME(usize, bytes_written));
}

OPT(usize) bufwriter_putchar(bufwriter_t *bw, char c)
{
    return (bufwriter_write(bw, &c, 1));
}

OPT(usize) bufwriter_write(bufwriter_t *bw, const void *raw_buffer, usize_t n)
{
    const u8_t *buffer = raw_buffer;
    usize_t bytes_written = n;

    if (bw->cursor + n >= bw->buffer_size)
        bufwriter_flush(bw);
    if (n >= bw->buffer_size)
        bytes_written = bw->write_cb(bw->user_data, buffer, n).v;
    else {
        for (usize_t i = 0; i < n; i++)
            bw->buffer[bw->cursor + i] = buffer[i];
        bw->cursor += n;
    }
    return (SOME(usize, bytes_written));
}
