/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_calloc
*/

#include <stdlib.h>
#include "my/mem.h"

void *my_calloc(usize_t nmemb, usize_t size)
{
    void *buf = NULL;

#if defined(MY_ALLOW_FUN_CALLOC)
    buf = calloc(nmemb, size);
#else
    buf = my_malloc(nmemb * size);
    if (buf != NULL)
        my_memset(buf, 0, nmemb * size);
#endif
    return (buf);
}
