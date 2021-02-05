/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** list_clear
*/

#include <stddef.h>
#include "my/mem.h"
#include "my/collections/list.h"

void list_clear(list_t *self)
{
    list_node_t *node = self->head;
    list_node_t *next = NULL;

    if (node == NULL)
        return;
    node->previous->next = NULL;
    while (node != NULL) {
        next = node->next;
        my_free(node);
        node = next;
    }
    self->len = 0;
    self->head = NULL;
}

void list_clear_with(list_t *self, list_iter_fn_t *destroyer, void *user_data)
{
    if (destroyer != NULL)
        list_for_each(self, destroyer, user_data);
    list_clear(self);
}
