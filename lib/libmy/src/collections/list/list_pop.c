/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stdlib.h>
#include "my/collections/list.h"
#include "priv.h"

OPT(ptr) list_pop_front(list_t *self)
{
    if (self->head == NULL)
        return (NONE(ptr));
    self->head = self->head->next;
    return (list_pop_back(self));
}

OPT(ptr) list_pop_back(list_t *self)
{
    void *val = NULL;

    if (self->head == NULL)
        return (NONE(ptr));
    val = list__destroy_node(&self->cache, self->head->previous);
    self->len--;
    if (self->len == 0)
        self->head = NULL;
    return (SOME(ptr, val));
}
