/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stddef.h>
#include "my/my.h"
#include "my/collections/list.h"
#include "priv.h"

list_t *list_new(void)
{
    return (list_with_capacity(32));
}

list_t *list_with_capacity(usize_t capacity)
{
    list_t *ls = my_calloc(1, sizeof(list_t));

    if (ls == NULL)
        return (NULL);
    ls->cache = list__create_cache(capacity);
    ls->head = NULL;
    ls->len = 0;
    return (ls);
}
