/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Random number generator
*/

#include <stdlib.h>
#include "my/rand.h"

i32_t my_rand(void)
{
#if defined(MY_ALLOW_FUN_RAND)
    return (rand());
#else
    return (0);
#endif
}

i32_t my_rand_r(u32_t *seedp)
{
#if defined(MY_ALLOW_FUN_RAND_R)
    return (rand_r(seedp));
#else
    (void)(seedp);
    return (0);
#endif
}

void my_srand(u32_t seed)
{
#if defined(MY_ALLOW_FUN_SRAND)
    srand(seed);
#else
    (void)(seed);
#endif
}
