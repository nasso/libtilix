/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Private linked list functions implementation
*/

#include "my/collections/list.h"
#include "../priv.h"

void list__insert_before(list_node_t *self, list_node_t *other)
{
    other->next = self;
    other->previous = self->previous;
    other->previous->next = other;
    other->next->previous = other;
}

void list__insert_after(list_node_t *self, list_node_t *other)
{
    other->next = self->next;
    other->previous = self;
    other->previous->next = other;
    other->next->previous = other;
}
