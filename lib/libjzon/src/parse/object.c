/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JSON object parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"
#include "priv.h"

static char *read_key(const char **str)
{
    char *key = NULL;
    OPT(jzon_parser_res) res = jzon_parse__ws(*str);

    res = jzon_parse_string(res.v.rem);
    if (!res.is_some)
        return (NULL);
    key = my_cstrdup(jzon_str(res.v.u.jz));
    jzon_drop(res.v.u.jz);
    res = jzon_parse__ws(res.v.rem);
    *str = res.v.rem;
    return (key);
}

static jzon_t read_element(const char **str)
{
    OPT(jzon_parser_res) res = jzon_parse_element(*str);

    if (!res.is_some)
        return (NULL);
    *str = res.v.rem;
    return (res.v.u.jz);
}

static bool read_member(const char **str, jzon_t obj)
{
    char *key = read_key(str);
    jzon_t elem = NULL;

    if (key == NULL || **str != ':') {
        my_free(key);
        return (true);
    }
    (*str)++;
    elem = read_element(str);
    if (elem == NULL || jzon_setk(obj, key, elem)) {
        my_free(key);
        return (true);
    }
    my_free(key);
    return (false);
}

static bool read_member_list(const char **str, jzon_t obj)
{
    if (read_member(str, obj))
        return (false);
    while (**str == ',') {
        (*str)++;
        if (read_member(str, obj))
            return (true);
    }
    return (false);
}

OPT(jzon_parser_res) jzon_parse_object(const char *str)
{
    jzon_parser_res_t res;

    if (*str != '{')
        return (NONE(jzon_parser_res));
    res.rem = jzon_parse__ws(str + 1).v.rem;
    res.u.jz = jzon_create_obj();
    if (res.u.jz == NULL || read_member_list(&res.rem, res.u.jz)) {
        jzon_drop(res.u.jz);
        return (NONE(jzon_parser_res));
    }
    if (*res.rem != '}') {
        jzon_drop(res.u.jz);
        return (NONE(jzon_parser_res));
    }
    res.rem++;
    return (SOME(jzon_parser_res, res));
}
