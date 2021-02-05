/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion function for %p
*/

#include <stdarg.h>
#include "my/my.h"
#include "my/fmt/priv/converter.h"

usize_t my_fmt__converter_fn_p(my_fmt__converter_t *cv, bufwriter_t *bw,
    va_list ap)
{
    cv->flags->alternate = 1;
    cv->len_mod = MY_FMT__LEN_MOD_PTR;
    cv->conversion_specifier = 'x';
    return (my_fmt__converter_fn_u(cv, bw, ap));
}
