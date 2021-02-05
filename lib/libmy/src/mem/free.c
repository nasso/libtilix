/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_free
*/

#include <stdlib.h>
#include "my/my.h"

void my_free(void *ptr)
{
    (void)(ptr);
#if defined(MY_ALLOW_FUN_FREE)
    if (ptr != NULL)
        free(ptr);
#endif
}
