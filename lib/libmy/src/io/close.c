/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_close
*/

#include <unistd.h>
#include "my/my.h"
#include "my/io.h"

int my_close(int fd)
{
    if (fd < 0)
        return (-1);
#if defined(MY_ALLOW_FUN_CLOSE)
    return (close(fd));
#else
    (void)(fd);
    return (-1);
#endif
}
