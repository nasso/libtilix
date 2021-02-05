/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Value parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"
#include "priv.h"

static jzon_parser_fn_t *const PARSERS[] = {
    &jzon_parse_object,
    &jzon_parse_array,
    &jzon_parse_string,
    &jzon_parse_number,
    &jzon_parse_bool,
    &jzon_parse_null,
};

static const usize_t PARSER_COUNT = sizeof(PARSERS) / sizeof(jzon_parser_fn_t*);

OPT(jzon_parser_res) jzon_parse_value(const char *str)
{
    OPT(jzon_parser_res) res = NONE(jzon_parser_res);

    for (usize_t i = 0; !res.is_some && i < PARSER_COUNT; i++)
        res = PARSERS[i](str);
    return (res);
}
