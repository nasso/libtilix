/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Element parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"
#include "priv.h"

OPT(jzon_parser_res) jzon_parse_element(const char *str)
{
    OPT(jzon_parser_res) res = NONE(jzon_parser_res);

    res = jzon_parse__ws(str);
    res = jzon_parse_value(res.v.rem);
    if (!res.is_some)
        return (NONE(jzon_parser_res));
    res.v.rem = jzon_parse__ws(res.v.rem).v.rem;
    return (res);
}
