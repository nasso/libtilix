/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_sstr_clone implementation
*/

#include "my/my.h"
#include "my/sstr.h"

char *my_sstr_clone(sstr_t self)
{
    return (my_cstrndup(self.ptr, self.len));
}
