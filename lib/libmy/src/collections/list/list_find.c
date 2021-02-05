/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "my/types.h"
#include "my/collections/list.h"
#include "priv.h"

OPT(ptr) list_find_with(list_t *self, list_find_fn_t *fn, void *element)
{
    list_node_t *node = self->head;

    if (node == NULL)
        return (NONE(ptr));
    for (usize_t i = 0; i < self->len; i++) {
        if (fn ? fn(element, node->val) : (element == node->val))
            return (SOME(ptr, node->val));
        node = node->next;
    }
    return (NONE(ptr));
}

OPT(ptr) list_find(list_t *self, void *element)
{
    return (list_find_with(self, NULL, element));
}
