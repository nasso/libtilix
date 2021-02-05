/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Random number generator
*/

#include <time.h>
#include "my/time.h"

u64_t my_time(void)
{
#if defined(MY_ALLOW_FUN_TIME)
    return ((u64_t) time(NULL));
#else
    return (0);
#endif
}
