/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_format implementation
*/

#include <stddef.h>
#include <stdarg.h>
#include "my/my.h"
#include "my/io.h"

static const int BUFFER_SIZE = 2048;

char *my_format(char const *fmt, ...)
{
    va_list ap;
    char *str = NULL;
    bufwriter_t *bw = cstrwriter_new(&str, BUFFER_SIZE);

    if (bw == NULL)
        return (NULL);
    va_start(ap, fmt);
    my_vbufprintf(bw, fmt, ap);
    va_end(ap);
    bufwriter_free(bw);
    return (str);
}
