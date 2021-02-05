/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Buffered reader
*/

#ifndef LIBMY_BUFREADER_H
#define LIBMY_BUFREADER_H

#include "my/types.h"

typedef OPT(usize) (bufreader_read_cb)(void*, void*, usize_t);
typedef void (bufreader_free_cb)(void*);

typedef struct bufreader {
    u8_t *buffer;
    usize_t buffer_size;
    usize_t bytes_left;
    usize_t cursor;
    bool ended;
    void *user_data;
    bufreader_read_cb *read_cb;
    bufreader_free_cb *free_cb;
} bufreader_t;

bufreader_t *bufreader_new(usize_t buf_size);
void bufreader_free(bufreader_t*);
char bufreader_getchar(bufreader_t*);
char bufreader_peekchar(bufreader_t*);
char *bufreader_read_until(bufreader_t*, OPT(char) ch);
char *bufreader_read_line(bufreader_t*);
char *bufreader_read_all(bufreader_t*);
OPT(usize) bufreader_read(bufreader_t*, void*, usize_t);
OPT(u8) bufreader_read_u8(bufreader_t*);
OPT(u16) bufreader_read_u16(bufreader_t*);
OPT(u32) bufreader_read_u32(bufreader_t*);
OPT(u64) bufreader_read_u64(bufreader_t*);
OPT(usize) bufreader_read_usize(bufreader_t*);

#endif /* LIBMY_BUFREADER_H */
