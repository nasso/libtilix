/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_read
*/

#include <stdlib.h>
#include <unistd.h>
#include "my/my.h"
#include "my/io.h"

OPT(usize) my_read(fd_t fd, void *buf, usize_t count)
{
    isize_t ret = 0;

#if defined(MY_ALLOW_FUN_READ)
    ret = read(fd, buf, count);
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
