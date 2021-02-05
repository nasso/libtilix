/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_printf, my_fprintf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my/my.h"
#include "my/io.h"

OPT(usize) my_vfprintf(fd_t fd, char const *fmt, va_list ap)
{
    OPT(usize) ret = NONE(usize);
    bufwriter_t *bw = filewriter_from(fd, 2048);

    if (bw == NULL)
        return (NONE(usize));
    ret = my_vbufprintf(bw, fmt, ap);
    bufwriter_free(bw);
    return (ret);
}

OPT(usize) my_bufprintf(bufwriter_t *bw, char const *fmt, ...)
{
    va_list ap;
    OPT(usize) ret = NONE(usize);

    va_start(ap, fmt);
    ret = my_vbufprintf(bw, fmt, ap);
    va_end(ap);
    return (ret);
}

OPT(usize) my_printf(char const *fmt, ...)
{
    va_list ap;
    OPT(usize) ret = NONE(usize);

    va_start(ap, fmt);
    ret = my_vfprintf(1, fmt, ap);
    va_end(ap);
    return (ret);
}

OPT(usize) my_fprintf(fd_t fd, char const *fmt, ...)
{
    va_list ap;
    OPT(usize) ret = NONE(usize);

    va_start(ap, fmt);
    ret = my_vfprintf(fd, fmt, ap);
    va_end(ap);
    return (ret);
}
