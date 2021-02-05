/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** read_until function implementation
*/

#include "my/my.h"
#include "my/io.h"

char *bufreader_read_until(bufreader_t *self, OPT(char) ch)
{
    char *str = NULL;
    bufwriter_t *bw = NULL;
    char c = bufreader_peekchar(self);

    if (self->ended)
        return (NULL);
    bw = cstrwriter_new(&str, self->buffer_size);
    while (!self->ended) {
        c = bufreader_getchar(self);
        bufwriter_putchar(bw, c);
        if (ch.is_some && c == ch.v)
            break;
    }
    bufwriter_free(bw);
    return (str);
}

char *bufreader_read_all(bufreader_t *self)
{
    return (bufreader_read_until(self, NONE(char)));
}

char *bufreader_read_line(bufreader_t *self)
{
    return (bufreader_read_until(self, SOME(char, '\n')));
}
