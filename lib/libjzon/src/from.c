/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** JZON from_* constructors
*/

#include "my/my.h"
#include "my/io.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"

jzon_t jzon_from(const char *cstr)
{
    OPT(jzon_parser_res) res = jzon_parse_json(cstr);

    if (!res.is_some)
        return (NULL);
    return (res.v.u.jz);
}

jzon_t jzon_from_reader(bufreader_t *reader)
{
    jzon_t self = NULL;
    char *str = bufreader_read_all(reader);

    if (str == NULL)
        return (NULL);
    self = jzon_from(str);
    my_free(str);
    return (self);
}

jzon_t jzon_from_path(const char *path)
{
    jzon_t self = NULL;
    bufreader_t *br = filereader_open(path, 1024);

    if (br == NULL)
        return (NULL);
    self = jzon_from_reader(br);
    bufreader_free(br);
    return (self);
}

jzon_t jzon_from_file(fd_t fd)
{
    jzon_t self = NULL;
    bufreader_t *br = filereader_from(fd, 1024);

    if (br == NULL)
        return (NULL);
    self = jzon_from_reader(br);
    bufreader_free(br);
    return (self);
}
