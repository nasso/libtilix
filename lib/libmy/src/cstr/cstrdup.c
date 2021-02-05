/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** strdup rewrite
*/

#include "my/cstr.h"

char *my_cstrdup(const char *str)
{
    return (my_cstrndup(str, my_cstrlen(str)));
}
