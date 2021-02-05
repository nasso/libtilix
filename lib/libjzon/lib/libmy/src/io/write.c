/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_write
*/

#include <stdlib.h>
#include <unistd.h>
#include "my/my.h"
#include "my/io.h"

OPT(usize) my_write(fd_t fd, const void *buf, usize_t count)
{
    isize_t ret = 0;

#if defined(MY_ALLOW_FUN_WRITE)
    ret = write(fd, buf, count);
    if (ret < 0)
        return (NONE(usize));
    return (SOME(usize, ret));
#else
    (void)(ret);
    (void)(fd);
    (void)(buf);
    (void)(count);
    return (NONE(usize));
#endif
}
