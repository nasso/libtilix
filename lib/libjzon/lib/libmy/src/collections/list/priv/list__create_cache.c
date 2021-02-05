/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** list__create_cache implementation
*/

#include "my/my.h"
#include "../priv.h"

list_node_cache_t list__create_cache(usize_t capacity)
{
    list_node_cache_t cache;

    cache.capacity = capacity;
    cache.len = 0;
    cache.nodes = my_malloc(capacity * sizeof(list_node_t*));
    return (cache);
}
