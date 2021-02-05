/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Path manipulation utils
*/

#ifndef LIBMY_PATH_H
#define LIBMY_PATH_H

#include "my/types.h"

char *my_path_join(sstr_t path, sstr_t other);
bool my_path_is_abs(sstr_t path);
OPT(sstr) my_path_parent(sstr_t path);

#endif /* LIBMY_PATH_H */
