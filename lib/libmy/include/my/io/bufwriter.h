/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Buffered writer
*/

#ifndef LIBMY_BUFWRITER_H
#define LIBMY_BUFWRITER_H

#include "my/my.h"

typedef OPT(usize) (bufwriter_write_cb)(void*, const void*, usize_t);
typedef void (bufwriter_free_cb)(void*);

typedef struct bufwriter {
    u8_t *buffer;
    usize_t buffer_size;
    usize_t cursor;
    bool ended;
    void *user_data;
    bufwriter_write_cb *write_cb;
    bufwriter_free_cb *free_cb;
} bufwriter_t;

bufwriter_t *bufwriter_new(usize_t buf_size);
void bufwriter_free(bufwriter_t*);
OPT(usize) bufwriter_putchar(bufwriter_t*, char);
OPT(usize) bufwriter_write(bufwriter_t*, const void*, usize_t);
OPT(usize) bufwriter_flush(bufwriter_t*);
OPT(usize) bufwriter_write_u8(bufwriter_t*, u8_t);
OPT(usize) bufwriter_write_u16(bufwriter_t*, u16_t);
OPT(usize) bufwriter_write_u32(bufwriter_t*, u32_t);
OPT(usize) bufwriter_write_u64(bufwriter_t*, u64_t);
OPT(usize) bufwriter_write_usize(bufwriter_t*, usize_t);

#endif /* LIBMY_BUFWRITER_H */
