/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JSON number parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"
#include "priv.h"

static bool parse_int(const char **str, f64_t *nb)
{
    bool found_digit = false;

    if (**str == '0') {
        (*str)++;
        return (false);
    }
    while (**str && my_cstrchr("0123456789", **str)) {
        found_digit = true;
        *nb *= 10;
        *nb += **str - '0';
        (*str)++;
    }
    return (!found_digit);
}

static bool parse_frac(const char **str, f64_t *nb)
{
    if (**str != '.')
        return (false);
    (*str)++;
    for (f64_t i = 10; **str && my_cstrchr("0123456789", **str); i *= 10.0) {
        *nb += (**str - '0') / i;
        (*str)++;
    }
    return (false);
}

static bool parse_exp(const char **str, f64_t *nb)
{
    u64_t e = 0;
    bool sign = true;

    if (**str != 'e' && **str != 'E')
        return (false);
    (*str)++;
    if (**str == '-' || **str == '+') {
        sign = **str == '+';
        (*str)++;
    }
    while (**str && my_cstrchr("0123456789", **str)) {
        e = (e * 10) + (**str - '0');
        (*str)++;
    }
    while (e) {
        *nb *= sign ? 10.0 : 0.1;
        e--;
    }
    return (false);
}

OPT(jzon_parser_res) jzon_parse_number(const char *str)
{
    jzon_parser_res_t res;
    f64_t nb = 0;
    f64_t sign = 1.0;

    if (*str == '-') {
        str++;
        sign = -1.0;
    }
    if (parse_int(&str, &nb) || parse_frac(&str, &nb) || parse_exp(&str, &nb))
        return (NONE(jzon_parser_res));
    res.rem = str;
    res.u.jz = jzon_create_num(nb * sign);
    if (res.u.jz == NULL)
        return (NONE(jzon_parser_res));
    return (SOME(jzon_parser_res, res));
}
