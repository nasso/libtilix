/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_path_parent implementation
*/

#include "my/my.h"
#include "my/path.h"

OPT(sstr) my_path_parent(sstr_t path)
{
    OPT(usize) last_slash = NONE(usize);

    for (usize_t i = path.len; i > 0 && !last_slash.is_some; i--)
        if (path.ptr[i - 1] == '/' && i < path.len)
            last_slash = SOME(usize, i - 1);
    if (!last_slash.is_some)
        return (NONE(sstr));
    return (SOME(sstr, my_sstr_sub(path, 0, last_slash.v)));
}
