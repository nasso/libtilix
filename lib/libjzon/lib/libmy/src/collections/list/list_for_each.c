/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Linked list implementation
*/

#include <stddef.h>
#include "my/types.h"
#include "my/collections/list.h"

OPT(i32) list_for_each(list_t *self, list_iter_fn_t *fn, void *element)
{
    OPT(i32) err = NONE(i32);

    LIST_FOR_EACH_AND(self, iter, !err.is_some)
        err = fn(element, iter.v);
    return (err);
}
