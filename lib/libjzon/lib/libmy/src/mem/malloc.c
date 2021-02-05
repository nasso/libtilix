/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_malloc
*/

#include <stdlib.h>
#include "my/my.h"

void *my_malloc(usize_t size)
{
    void *buf = NULL;

    (void)(size);
#if defined(MY_ALLOW_FUN_MALLOC)
    buf = malloc(size);
#endif
    return (buf);
}
