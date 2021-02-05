/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Parser entry point
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"

OPT(jzon_parser_res) jzon_parse_json(const char *str)
{
    return (jzon_parse_element(str));
}
