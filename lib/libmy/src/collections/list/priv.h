/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Private functions used by the linked list implementation
*/

#ifndef LIBMY_COLLECTIONS_LIST_PRIV_H
#define LIBMY_COLLECTIONS_LIST_PRIV_H

#include <stddef.h>
#include "my/types.h"
#include "my/collections/list.h"

list_node_cache_t list__create_cache(usize_t);
list_node_t *list__get_nth_node(list_node_t*, usize_t);
list_node_t *list__create_node(list_node_cache_t*, void*);
void *list__destroy_node(list_node_cache_t*, list_node_t*);
void list__insert_before(list_node_t*, list_node_t*);
void list__insert_after(list_node_t*, list_node_t*);

#endif /* LIBMY_COLLECTIONS_LIST_PRIV_H */
