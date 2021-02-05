/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Skip whitespace
*/

#include "my/my.h"
#include "jzon/parser.h"
#include "../priv.h"

OPT(jzon_parser_res) jzon_parse__ws(const char *str)
{
    jzon_parser_res_t res;

    res.rem = str;
    while (*res.rem && my_cstrchr(" \n\r\t", *res.rem))
        res.rem++;
    return (SOME(jzon_parser_res, res));
}
