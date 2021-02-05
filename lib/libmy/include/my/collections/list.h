/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Circular doubly-linked list data structure
*/

#ifndef LIBMY_COLLECTIONS_LIST_H
#define LIBMY_COLLECTIONS_LIST_H

#include <stdbool.h>
#include <stdarg.h>
#include "my/types.h"

#define LIST_FOR_EACH_AND(self, name, cond) \
    for (list_iter_t name = list_iter(self); \
        !list_iter_ended(&name) && (cond); list_iter_next(&name))

#define LIST_FOR_EACH(self, name) LIST_FOR_EACH_AND(self, name, true)

typedef OPT(i32) (list_iter_fn_t)(void *user_data, void *element);
typedef bool (list_find_fn_t)(void *user_data, void *element);

typedef struct list_node {
    struct list_node *next;
    struct list_node *previous;
    void *val;
} list_node_t;

typedef struct {
    list_node_t **nodes;
    usize_t len;
    usize_t capacity;
} list_node_cache_t;

typedef struct {
    list_node_cache_t cache;
    list_node_t *head;
    usize_t len;
} list_t;

typedef struct {
    const list_node_t *next;
    const list_t *list;
    usize_t i;
    void *v;
} list_iter_t;

list_t *list_new(void);
list_t *list_from(usize_t, ...);
list_t *list_from_var(usize_t, va_list);
list_t *list_from_arr(usize_t, void**);
list_t *list_with_capacity(usize_t);
void list_destroy(list_t*);
void list_destroy_with(list_t*, list_iter_fn_t*, void*);
bool list_push_front(list_t*, void*);
bool list_push_back(list_t*, void*);
bool list_insert(list_t*, usize_t, void*);
OPT(ptr) list_set(list_t*, usize_t, void*);
OPT(ptr) list_pop_front(list_t*);
OPT(ptr) list_pop_back(list_t*);
OPT(ptr) list_remove(list_t*, usize_t);
OPT(ptr) list_remove_element(list_t*, void*, list_find_fn_t*);
void list_clear(list_t*);
void list_clear_with(list_t*, list_iter_fn_t*, void*);
OPT(ptr) list_get(const list_t*, usize_t);
OPT(ptr) list_head(const list_t*);
OPT(ptr) list_tail(const list_t*);
OPT(ptr) list_find(list_t*, void*);
OPT(ptr) list_find_with(list_t*, list_find_fn_t*, void*);
OPT(i32) list_for_each(list_t*, list_iter_fn_t*, void*);

list_iter_t list_iter(const list_t*);
bool list_iter_ended(const list_iter_t*);
void list_iter_next(list_iter_t*);

#endif /* LIBMY_COLLECTIONS_LIST_H */
