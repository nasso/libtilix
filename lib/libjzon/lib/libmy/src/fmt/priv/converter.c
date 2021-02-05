/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Formatter
*/

#include <stddef.h>
#include "my/my.h"
#include "my/fmt/priv/converter.h"

void my_fmt__converter_free(my_fmt__converter_t *conv)
{
    if (conv == NULL)
        return;
    if (conv->flags)
        my_free(conv->flags);
    my_free(conv);
}
