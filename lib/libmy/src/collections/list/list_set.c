/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdbool.h>
#include "my/types.h"
#include "my/collections/list.h"
#include "priv.h"

OPT(ptr) list_set(list_t *ls, usize_t i, void *data)
{
    list_node_t *node = NULL;
    void *old_val = NULL;

    if (i >= ls->len)
        return (NONE(ptr));
    node = list__get_nth_node(ls->head, i);
    old_val = node->val;
    node->val = data;
    return (SOME(ptr, old_val));
}
