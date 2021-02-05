/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion function for %%
*/

#include <stdarg.h>
#include "my/my.h"
#include "my/fmt/priv/converter.h"

usize_t my_fmt__converter_fn_c(my_fmt__converter_t *cv, bufwriter_t *bw,
    va_list ap)
{
    usize_t bytes_written = 0;
    unsigned char c = (unsigned char) va_arg(ap, int);

    if (cv->flags->leftpad)
        bytes_written += bufwriter_putchar(bw, c).v;
    for (isize_t i = 0; i + 1 < cv->field_width; i++)
        bytes_written += bufwriter_putchar(bw, ' ').v;
    if (!cv->flags->leftpad)
        bytes_written += bufwriter_putchar(bw, c).v;
    return (bytes_written);
}
