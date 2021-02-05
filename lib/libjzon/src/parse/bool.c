/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JSON bool parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"
#include "priv.h"

static OPT(jzon_parser_res) create_bool(const char *rem, bool val)
{
    jzon_parser_res_t res;

    res.rem = rem;
    res.u.jz = jzon_create_bool(val);
    if (res.u.jz == NULL)
        return (NONE(jzon_parser_res));
    return (SOME(jzon_parser_res, res));
}

OPT(jzon_parser_res) jzon_parse_bool(const char *str)
{
    OPT(jzon_parser_res) res = NONE(jzon_parser_res);

    res = jzon_parse__tag(str, "true");
    if (res.is_some)
        return (create_bool(res.v.rem, true));
    res = jzon_parse__tag(str, "false");
    if (res.is_some)
        return (create_bool(res.v.rem, false));
    return (res);
}
