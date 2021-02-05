/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion functions for %s and %S
*/

#include <stddef.h>
#include <stdarg.h>
#include "my/my.h"
#include "my/cstr.h"
#include "my/fmt/priv/converter.h"

static usize_t put_non_printable(bufwriter_t *bw, char c)
{
    usize_t bytes_written = 0;

    bytes_written += bw ? bufwriter_putchar(bw, '\\').v : 1;
    bytes_written += bw ? bufwriter_putchar(bw, '0' + (c / 0100 % 010)).v : 1;
    bytes_written += bw ? bufwriter_putchar(bw, '0' + (c / 010 % 010)).v : 1;
    bytes_written += bw ? bufwriter_putchar(bw, '0' + (c / 01 % 010)).v : 1;
    return (bytes_written);
}

static usize_t put_string(bufwriter_t *bw, my_fmt__converter_t *cv,
    char const *str, usize_t n)
{
    usize_t bytes_written = 0;
    char cv_spec = cv->conversion_specifier;

    if (cv_spec != 'S')
        return (bw == NULL ? n : bufwriter_write(bw, str, n).v);
    for (usize_t i = 0; i < n; i++) {
        if (str[i] < 32 || str[i] >= 127)
            bytes_written += put_non_printable(bw, str[i]);
        else
            bytes_written += bw == NULL ? 1 : bufwriter_putchar(bw, str[i]).v;
    }
    return (bytes_written);
}

usize_t my_fmt__converter_fn_s(my_fmt__converter_t *cv, bufwriter_t *bw,
    va_list ap)
{
    usize_t bytes_written = 0;
    isize_t n = cv->precision;
    isize_t width = 0;
    sstr_t str;

    if (cv->len_mod == MY_FMT__LEN_MOD_Z)
        str = va_arg(ap, sstr_t);
    else
        str = my_sstr(va_arg(ap, char*));
    if (n < 0)
        n = str.len;
    width = put_string(NULL, cv, str.ptr, n);
    if (cv->flags->leftpad)
        bytes_written += put_string(bw, cv, str.ptr, n);
    for (isize_t i = 0; i < cv->field_width - width; i++)
        bytes_written += bufwriter_putchar(bw, ' ').v;
    if (!cv->flags->leftpad)
        bytes_written += put_string(bw, cv, str.ptr, n);
    return (bytes_written);
}
