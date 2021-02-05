/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** IO utils
*/

#ifndef LIBMY_IO_H
#define LIBMY_IO_H

#include <stdarg.h>
#include "my/types.h"
#include "my/io/bufreader.h"
#include "my/io/bufwriter.h"
#include "my/io/filereader.h"
#include "my/io/cstrreader.h"
#include "my/io/filewriter.h"
#include "my/io/cstrwriter.h"

fd_t my_open(const char *pathname, i32_t flags);
fd_t my_close(fd_t fd);
OPT(usize) my_write(fd_t fd, const void *buf, usize_t count);
OPT(usize) my_read(fd_t fd, void *buf, usize_t count);
OPT(usize) my_vbufprintf(bufwriter_t*, char const*, va_list);
OPT(usize) my_bufprintf(bufwriter_t*, char const*, ...);
OPT(usize) my_vfprintf(fd_t fd, char const*, va_list);
OPT(usize) my_fprintf(fd_t fd, char const*, ...);
OPT(usize) my_printf(char const*, ...);
OPT(usize) my_putchar(char c);
OPT(usize) my_putchar_err(char c);
OPT(usize) my_putcstr(char const *str);
OPT(usize) my_putcstr_err(char const *str);

#endif /* LIBMY_IO_H */
