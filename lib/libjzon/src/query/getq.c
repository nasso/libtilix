/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON getq implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

static bool is_ident_char(char c)
{
    bool valid = false;

    valid = valid || (c >= 'a' && c <= 'z');
    valid = valid || (c >= 'A' && c <= 'Z');
    valid = valid || (c >= '0' && c <= '9');
    valid = valid || my_cstrchr("$_", c);
    return (valid);
}

static jzon_t process_key_fetch(const char **qstr, const jzon_t jz)
{
    char *key = NULL;
    usize_t klen = 0;
    jzon_t child = NULL;

    if (**qstr != '.')
        return (NULL);
    (*qstr)++;
    while (**qstr && my_cstrchr(" \t\n\r", **qstr))
        (*qstr)++;
    while ((*qstr)[klen] && is_ident_char((*qstr)[klen]))
        klen++;
    key = my_cstrndup(*qstr, klen);
    *qstr += klen;
    if (key == NULL)
        return (NULL);
    child = jzon_getk(jz, key);
    my_free(key);
    return (child);
}

static jzon_t process_ind_fetch(const char **qstr, const jzon_t jz)
{
    bool digit_found = false;
    i32_t ind = 0;

    if (**qstr != '[')
        return (NULL);
    (*qstr)++;
    while (**qstr && my_cstrchr(" \t\n\r", **qstr))
        (*qstr)++;
    ind = my_cstr_getnbr(*qstr);
    while (**qstr && **qstr >= '0' && **qstr <= '9') {
        digit_found = true;
        (*qstr)++;
    }
    while (**qstr && my_cstrchr(" \t\n\r", **qstr))
        (*qstr)++;
    if (**qstr != ']' || !digit_found || ind < 0)
        return (NULL);
    (*qstr)++;
    return (jzon_geti(jz, ind));
}

static jzon_t process_query(const char **qstr, const jzon_t jz)
{
    jzon_t child = NULL;

    while (**qstr && my_cstrchr(" \t\n\r", **qstr))
        (*qstr)++;
    switch (**qstr) {
    case '.':
        child = process_key_fetch(qstr, jz);
        break;
    case '[':
        child = process_ind_fetch(qstr, jz);
        break;
    default:
        break;
    }
    while (**qstr && my_cstrchr(" \t\n\r", **qstr))
        (*qstr)++;
    return (child);
}

jzon_t jzon_getq(const jzon_t self, const char *query)
{
    jzon_t jz = jzon_iref(self);
    jzon_t sub_jz = NULL;

    while (jz != NULL && *query != '\0') {
        sub_jz = process_query(&query, jz);
        jzon_drop(jz);
        jz = sub_jz;
    }
    return (jz);
}
