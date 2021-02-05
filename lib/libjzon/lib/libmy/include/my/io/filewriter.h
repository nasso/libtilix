/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** File writer using a buffered writer
*/

#ifndef LIBMY_IO_FILEWRITER_H
#define LIBMY_IO_FILEWRITER_H

#include "my/io/bufwriter.h"

bufwriter_t *filewriter_from(fd_t fd, usize_t buf_size);
bufwriter_t *filewriter_open(char const *path, usize_t buf_size);

#endif /* LIBMY_IO_FILEWRITER_H */
