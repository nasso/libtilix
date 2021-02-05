/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_memmove tests
*/

#include <criterion/criterion.h>
#include "my/my.h"

Test(my_memmove, overlapping_data, .timeout = 1.0)
{
    char data[6] = {6, 2, 1, 0, 0, 0};

    my_memmove(&data[2], &data[0], 3);
    cr_assert_eq(data[2], 6);
    cr_assert_eq(data[3], 2);
    cr_assert_eq(data[4], 1);
    my_memmove(&data[1], &data[2], 3);
    cr_assert_eq(data[1], 6);
    cr_assert_eq(data[2], 2);
    cr_assert_eq(data[3], 1);
}
