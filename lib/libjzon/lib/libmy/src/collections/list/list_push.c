/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my/collections/list.h"
#include "priv.h"

bool list_push_front(list_t *self, void *data)
{
    list_node_t *node = list__create_node(&self->cache, data);

    if (node == NULL)
        return (true);
    if (self->head)
        list__insert_before(self->head, node);
    self->head = node;
    self->len++;
    return (false);
}

bool list_push_back(list_t *self, void *data)
{
    if (list_push_front(self, data))
        return (true);
    self->head = self->head->next;
    return (false);
}
