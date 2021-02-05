/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Private linked list functions implementation
*/

#include <stddef.h>
#include "my/my.h"
#include "my/collections/list.h"
#include "../priv.h"

void *list__destroy_node(list_node_cache_t *cache, list_node_t *node)
{
    void *val = node->val;

    node->previous->next = node->next;
    node->next->previous = node->previous;
    if (cache->len < cache->capacity) {
        cache->nodes[cache->len] = node;
        cache->len++;
    } else {
        my_free(node);
    }
    return (val);
}
