/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Random number generator
*/

#ifndef LIBMY_RAND_H
#define LIBMY_RAND_H

#include "my/types.h"

i32_t my_rand(void);
i32_t my_rand_r(u32_t *seedp);
void my_srand(u32_t seed);

#endif /* LIBMY_RAND_H */
