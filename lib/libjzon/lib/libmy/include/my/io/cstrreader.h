/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Buffered reader implementation that reads a cstring
*/

#ifndef LIBMY_IO_CSTRREADER_H
#define LIBMY_IO_CSTRREADER_H

#include "my/io/bufreader.h"

bufreader_t *cstrreader_new(const char *str, usize_t buf_size);

#endif /* LIBMY_IO_CSTRREADER_H */
