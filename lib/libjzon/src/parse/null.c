/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JSON null parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"
#include "priv.h"

OPT(jzon_parser_res) jzon_parse_null(const char *str)
{
    OPT(jzon_parser_res) res = jzon_parse__tag(str, "null");

    if (!res.is_some)
        return (NONE(jzon_parser_res));
    res.v.u.jz = jzon_create_null();
    if (res.v.u.jz == NULL)
        return (NONE(jzon_parser_res));
    return (res);
}
