/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "my/my.h"
#include "my/io.h"
#include "my/fmt/priv/converter.h"

static usize_t do_directive(bufwriter_t *bw, char const **fmt, va_list ap)
{
    usize_t bytes_written = 0;
    char const *directive_start = *fmt;
    my_fmt__converter_t *conv = my_fmt__converter_new(fmt, ap);

    if (conv == NULL) {
        bytes_written = bufwriter_putchar(bw, '%').v;
        *fmt = directive_start;
    } else {
        bytes_written = conv->cv_fn(conv, bw, ap);
        my_fmt__converter_free(conv);
    }
    return (bytes_written);
}

static void flush_if(bufwriter_t *bw, int condition)
{
    if (condition)
        bufwriter_flush(bw);
}

OPT(usize) my_vbufprintf(bufwriter_t *bw, char const *fmt, va_list ap)
{
    usize_t bytes_written = 0;

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            bytes_written += do_directive(bw, &fmt, ap);
        } else {
            bytes_written += bufwriter_putchar(bw, *fmt).v;
            flush_if(bw, *fmt == '\n');
            fmt++;
        }
    }
    return (SOME(usize, bytes_written));
}
