/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Implementation of my_putchar.
*/

#include <unistd.h>
#include "my/my.h"
#include "my/io.h"

OPT(usize) my_putchar(char c)
{
    return (my_write(1, &c, 1));
}

OPT(usize) my_putchar_err(char c)
{
    return (my_write(2, &c, 1));
}
