/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JSON string parser
*/

#include "my/my.h"
#include "my/io.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"
#include "priv.h"

static const struct { char e; char c; } SIMPLE_ESCAPES[] = {
    {'"', '"'},
    {'\\', '\\'},
    {'/', '/'},
    {'b', '\b'},
    {'f', '\f'},
    {'n', '\n'},
    {'r', '\r'},
    {'t', '\t'},
};

static const usize_t SIMPLE_ESCAPE_COUNT = 8;

static bool process_escape(const char **in, bufwriter_t *out)
{
    if (**in != '\\')
        return (true);
    (*in)++;
    for (usize_t i = 0; i < SIMPLE_ESCAPE_COUNT; i++)
        if (**in == SIMPLE_ESCAPES[i].e) {
            bufwriter_putchar(out, SIMPLE_ESCAPES[i].c);
            (*in)++;
            return (false);
        }
    return (true);
}

static bool read_str(const char **in, bufwriter_t *out)
{
    if (**in != '"')
        return (true);
    (*in)++;
    while (**in && **in != '"') {
        if (**in != '\\') {
            bufwriter_putchar(out, **in);
            (*in)++;
        } else if (process_escape(in, out))
            return (true);
    }
    if (**in != '"')
        return (true);
    (*in)++;
    return (false);
}

OPT(jzon_parser_res) jzon_parse_string(const char *str)
{
    char *strbuf = NULL;
    bufwriter_t *bw = cstrwriter_new(&strbuf, 256);
    jzon_parser_res_t res;
    bool err = read_str(&str, bw);

    bufwriter_free(bw);
    if (err || strbuf == NULL) {
        my_free(strbuf);
        return (NONE(jzon_parser_res));
    }
    res.rem = str;
    res.u.jz = jzon_create_str(strbuf);
    my_free(strbuf);
    if (res.u.jz == NULL)
        return (NONE(jzon_parser_res));
    return (SOME(jzon_parser_res, res));
}
