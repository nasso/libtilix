/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Tag parser
*/

#include "my/my.h"
#include "jzon/parser.h"
#include "../priv.h"

OPT(jzon_parser_res) jzon_parse__tag(const char *str, const char *tag)
{
    usize_t len = my_cstrlen(tag);
    jzon_parser_res_t res;

    if (my_cstrncmp(str, tag, len) != 0)
        return (NONE(jzon_parser_res));
    res.rem = str + len;
    return (SOME(jzon_parser_res, res));
}
