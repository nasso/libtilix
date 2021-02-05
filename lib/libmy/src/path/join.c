/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_path_join implementation
*/

#include "my/my.h"
#include "my/path.h"

char *my_path_join(sstr_t path, sstr_t other)
{
    return (my_format("%zs/%zs", path, other));
}
