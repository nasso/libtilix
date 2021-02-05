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

static list_node_t *allocate_node(list_node_cache_t *cache)
{
    list_node_t *node = NULL;

    if (cache->len > 0) {
        cache->len--;
        node = cache->nodes[cache->len];
    } else {
        node = my_malloc(sizeof(list_node_t));
    }
    return (node);
}

list_node_t *list__create_node(list_node_cache_t *cache, void *data)
{
    list_node_t *node = allocate_node(cache);

    if (node == NULL)
        return (NULL);
    node->val = data;
    node->next = node;
    node->previous = node;
    return (node);
}
