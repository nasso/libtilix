/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_path_join implementation
*/

#include "my/my.h"
#include "my/path.h"

bool my_path_is_abs(sstr_t path)
{
    return (path.ptr[0] == '/');
}
