/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** strndup rewrite
*/

#include "my/my.h"
#include "my/cstr.h"

char *my_cstrndup(const char *str, usize_t n)
{
    char *cpy = NULL;

    if (str == NULL)
        return (NULL);
    cpy = my_malloc((n + 1) * sizeof(char));
    if (cpy == NULL)
        return (NULL);
    my_memcpy(cpy, str, n * sizeof(char));
    cpy[n] = '\0';
    return (cpy);
}
