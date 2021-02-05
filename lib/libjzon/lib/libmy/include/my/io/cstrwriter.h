/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Buffered writer implementation that writes to a dynamically allocated cstring
*/

#ifndef LIBMY_IO_CSTRWRITER_H
#define LIBMY_IO_CSTRWRITER_H

#include "my/io/bufwriter.h"

bufwriter_t *cstrwriter_new(char **dest, usize_t buf_size);

#endif /* LIBMY_IO_CSTRWRITER_H */
