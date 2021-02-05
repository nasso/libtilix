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

OPT(ptr) list_remove(list_t *self, usize_t i)
{
    OPT(ptr) val = NONE(ptr);
    list_node_t *head = self->head;

    if (i >= self->len)
        return (NONE(ptr));
    self->head = list__get_nth_node(head, i);
    if (self->head == head)
        head = head->next == head ? NULL : head->next;
    val = list_pop_front(self);
    self->head = head;
    return (val);
}
