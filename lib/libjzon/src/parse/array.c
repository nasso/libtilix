/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JSON array parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"
#include "priv.h"

static bool read_element(const char **str, jzon_t arr)
{
    OPT(jzon_parser_res) res = jzon_parse_element(*str);

    if (!res.is_some || jzon_push(arr, res.v.u.jz))
        return (true);
    *str = res.v.rem;
    return (false);
}

static bool read_element_list(const char **str, jzon_t arr)
{
    if (read_element(str, arr))
        return (false);
    while (**str == ',') {
        (*str)++;
        if (read_element(str, arr))
            return (true);
    }
    return (false);
}

OPT(jzon_parser_res) jzon_parse_array(const char *str)
{
    jzon_parser_res_t res;

    if (*str != '[')
        return (NONE(jzon_parser_res));
    res.rem = jzon_parse__ws(str + 1).v.rem;
    res.u.jz = jzon_create_arr();
    if (res.u.jz == NULL || read_element_list(&res.rem, res.u.jz)) {
        jzon_drop(res.u.jz);
        return (NONE(jzon_parser_res));
    }
    if (*res.rem != ']') {
        jzon_drop(res.u.jz);
        return (NONE(jzon_parser_res));
    }
    res.rem++;
    return (SOME(jzon_parser_res, res));
}
