/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Displays the characters of a string one-by-one.
*/

#include <unistd.h>
#include "my/cstr.h"
#include "my/my.h"
#include "my/io.h"

OPT(usize) my_putcstr(const char *str)
{
    return (my_write(1, str, my_cstrlen(str)));
}

OPT(usize) my_putcstr_err(const char *str)
{
    return (my_write(2, str, my_cstrlen(str)));
}
