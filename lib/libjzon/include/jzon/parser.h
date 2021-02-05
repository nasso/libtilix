/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON parser
*/

#ifndef LIBJZON_PARSER_H
#define LIBJZON_PARSER_H

#include "jzon/jzon.h"

typedef struct {
    const char *rem;
    union {
        jzon_t jz;
    } u;
} jzon_parser_res_t;

OPT_DEFINE(jzon_parser_res_t, jzon_parser_res)

OPT(jzon_parser_res) jzon_parse_json(const char *str);
OPT(jzon_parser_res) jzon_parse_element(const char *str);
OPT(jzon_parser_res) jzon_parse_value(const char *str);
OPT(jzon_parser_res) jzon_parse_object(const char *str);
OPT(jzon_parser_res) jzon_parse_array(const char *str);
OPT(jzon_parser_res) jzon_parse_string(const char *str);
OPT(jzon_parser_res) jzon_parse_number(const char *str);
OPT(jzon_parser_res) jzon_parse_bool(const char *str);
OPT(jzon_parser_res) jzon_parse_null(const char *str);

#endif /* LIBJZON_PARSER_H */
