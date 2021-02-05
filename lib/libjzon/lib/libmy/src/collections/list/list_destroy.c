/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stddef.h>
#include "my/my.h"
#include "my/collections/list.h"

void list_destroy(list_t *self)
{
    list_node_t *node = NULL;
    list_node_t *next = NULL;

    if (self == NULL)
        return;
    node = self->head;
    if (node != NULL) {
        node->previous->next = NULL;
        while (node != NULL) {
            next = node->next;
            my_free(node);
            node = next;
        }
    }
    for (usize_t i = 0; i < self->cache.len; i++)
        my_free(self->cache.nodes[i]);
    my_free(self->cache.nodes);
    my_free(self);
}

void list_destroy_with(list_t *self, list_iter_fn_t *destroyer, void *user_data)
{
    if (self == NULL)
        return;
    if (destroyer != NULL)
        list_for_each(self, destroyer, user_data);
    list_destroy(self);
}
