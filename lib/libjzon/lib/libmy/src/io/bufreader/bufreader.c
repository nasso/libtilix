/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Bufreader implementation
*/

#include "my/my.h"
#include "my/io.h"

bufreader_t *bufreader_new(usize_t buf_size)
{
    bufreader_t *br = my_malloc(sizeof(bufreader_t));

    if (br == NULL)
        return (NULL);
    br->buffer = my_malloc(sizeof(u8_t) * buf_size);
    if (br->buffer == NULL)
        return (NULL);
    br->buffer_size = buf_size;
    br->bytes_left = 0;
    br->cursor = 0;
    br->ended = 0;
    br->user_data = NULL;
    br->read_cb = NULL;
    br->free_cb = NULL;
    return (br);
}

void bufreader_free(bufreader_t *br)
{
    if (br == NULL)
        return;
    if (br->free_cb)
        br->free_cb(br->user_data);
    my_free(br->buffer);
    my_free(br);
}

char bufreader_getchar(bufreader_t *br)
{
    char c = bufreader_peekchar(br);

    br->bytes_left--;
    br->cursor++;
    return (c);
}

char bufreader_peekchar(bufreader_t *br)
{
    u8_t *buf = br->buffer;

    if (br->bytes_left == 0) {
        br->bytes_left = br->read_cb(br->user_data, buf, br->buffer_size).v;
        br->cursor = 0;
        br->ended = br->bytes_left == 0;
    }
    if (br->ended)
        return ('\0');
    return (buf[br->cursor]);
}

OPT(usize) bufreader_read(bufreader_t *br, void *raw_buffer, usize_t n)
{
    u8_t *buffer = raw_buffer;
    usize_t i = 0;
    usize_t read_bytes = 0;

    if (br->ended)
        return (NONE(usize));
    while (i < n && i < br->bytes_left) {
        buffer[i] = br->buffer[br->cursor + i];
        i++;
    }
    br->bytes_left = 0;
    read_bytes = i;
    if (n - i > 0)
        read_bytes += br->read_cb(br->user_data, buffer, n - i).v;
    br->ended = read_bytes == 0;
    return (SOME(usize, read_bytes));
}
