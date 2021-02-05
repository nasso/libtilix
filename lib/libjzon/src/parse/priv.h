/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Private header for the parser
*/

#ifndef LIBJZON_PARSE_PRIV_H
#define LIBJZON_PARSE_PRIV_H

#include "my/types.h"
#include "jzon/parser.h"

typedef OPT(jzon_parser_res) jzon_parser_fn_t(const char *str);

OPT(jzon_parser_res) jzon_parse__tag(const char *str, const char *tag);
OPT(jzon_parser_res) jzon_parse__ws(const char *str);

#endif /* LIBJZON_PARSE_PRIV_H */
