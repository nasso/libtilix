/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Vector tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my/cstr.h"
#include "my/collections/list.h"

static void redirect_all(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static OPT(i32) for_each_println(void *user_data, void *element)
{
    int *data = user_data;

    printf("%s\n", (char*) element);
    (*data)--;
    return (*data == 0 ? SOME(i32, 0) : NONE(i32));
}

TestSuite(list, .timeout = 1.0, .init = redirect_all);

Test(list, list_new)
{
    list_t *ls = list_new();

    cr_assert(ls != NULL);
    cr_assert_eq(ls->len, 0);
    list_destroy(ls);
}

Test(list, list_from)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert_eq(ls->len, 3);
    cr_assert_str_eq(ls->head->val, "owo");
    cr_assert_str_eq(ls->head->next->val, "uwu");
    cr_assert_str_eq(ls->head->next->next->val, "gay");
    cr_assert_eq(ls->head->previous, ls->head->next->next);
    cr_assert_eq(ls->head->next, ls->head->previous->previous);
    list_destroy(ls);
}

Test(list, list_from_arr)
{
    const char *data[3] = {"owo", "uwu", "gay"};
    list_t *ls = list_from_arr(3, (void**) data);

    cr_assert_eq(ls->len, 3);
    cr_assert_str_eq(ls->head->val, "owo");
    cr_assert_str_eq(ls->head->next->val, "uwu");
    cr_assert_str_eq(ls->head->next->next->val, "gay");
    cr_assert_eq(ls->head->previous, ls->head->next->next);
    cr_assert_eq(ls->head->next, ls->head->previous->previous);
    list_destroy(ls);
}

Test(list, list_clear)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    list_clear(ls);
    cr_assert_eq(ls->len, 0);
    cr_assert_null(ls->head);
    list_destroy(ls);
}

Test(list, list_clear_and_reinstert)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    list_clear(ls);
    cr_assert_eq(list_push_back(ls, "owo"), 0);
    cr_assert_eq(ls->len, 1);
    cr_assert_str_eq(ls->head->val, "owo");
    list_destroy(ls);
}

Test(list, list_push_back)
{
    list_t *ls = list_new();

    cr_assert_eq(list_push_back(ls, "owo"), 0);
    cr_assert_eq(list_push_back(ls, "uwu"), 0);
    cr_assert_eq(list_push_back(ls, "gay"), 0);
    cr_assert_eq(ls->len, 3);
    cr_assert_str_eq(ls->head->val, "owo");
    cr_assert_str_eq(ls->head->next->val, "uwu");
    cr_assert_str_eq(ls->head->next->next->val, "gay");
    cr_assert_eq(ls->head->previous, ls->head->next->next);
    cr_assert_eq(ls->head->next, ls->head->previous->previous);
    list_destroy(ls);
}

Test(list, list_push_front)
{
    list_t *ls = list_new();

    cr_assert_eq(list_push_front(ls, "owo"), 0);
    cr_assert_eq(list_push_front(ls, "uwu"), 0);
    cr_assert_eq(list_push_front(ls, "gay"), 0);
    cr_assert_eq(ls->len, 3);
    cr_assert_str_eq(ls->head->val, "gay");
    cr_assert_str_eq(ls->head->next->val, "uwu");
    cr_assert_str_eq(ls->head->next->next->val, "owo");
    cr_assert_eq(ls->head->previous, ls->head->next->next);
    cr_assert_eq(ls->head->next, ls->head->previous->previous);
    list_destroy(ls);
}

Test(list, list_pop_back)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(list_pop_back(ls).v, "gay");
    cr_assert_eq(ls->len, 2);
    cr_assert_str_eq(ls->head->val, "owo");
    cr_assert_str_eq(ls->head->next->val, "uwu");
    cr_assert_eq(ls->head->previous, ls->head->next);
    cr_assert_eq(ls->head->next, ls->head->previous);
    list_destroy(ls);
}

Test(list, list_pop_front)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(list_pop_front(ls).v, "owo");
    cr_assert_eq(ls->len, 2);
    cr_assert_str_eq(ls->head->val, "uwu");
    cr_assert_str_eq(ls->head->next->val, "gay");
    cr_assert_eq(ls->head->previous, ls->head->next);
    cr_assert_eq(ls->head->next, ls->head->previous);
    list_destroy(ls);
}

Test(list, list_get)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "uwu");
    cr_assert_str_eq(list_get(ls, 2).v, "gay");
    cr_assert_not(list_get(ls, 3).is_some);
    list_destroy(ls);
}

Test(list, list_set)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert(list_set(ls, 1, "baa").is_some);
    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "baa");
    cr_assert_str_eq(list_get(ls, 2).v, "gay");
    list_destroy(ls);
}

Test(list, list_remove)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(list_remove(ls, 1).v, "uwu");
    cr_assert_eq(ls->len, 2);
    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "gay");
    list_destroy(ls);
}

Test(list, list_remove_out_of_bounds)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert_not(list_remove(ls, 3).is_some);
    cr_assert_eq(ls->len, 3);
    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "uwu");
    cr_assert_str_eq(list_get(ls, 2).v, "gay");
    list_destroy(ls);
}

Test(list, list_remove_first)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(list_remove(ls, 0).v, "owo");
    cr_assert_eq(ls->len, 2);
    cr_assert_str_eq(list_get(ls, 0).v, "uwu");
    cr_assert_str_eq(list_get(ls, 1).v, "gay");
    list_destroy(ls);
}

Test(list, list_remove_last)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(list_remove(ls, 2).v, "gay");
    cr_assert_eq(ls->len, 2);
    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "uwu");
    list_destroy(ls);
}

Test(list, list_remove_element)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");
    OPT(ptr) val = list_remove_element(ls, "uwu", (list_find_fn_t*) &my_cstreq);

    cr_assert(val.is_some);
    cr_assert_str_eq(val.v, "uwu");
    cr_assert_eq(ls->len, 2);
    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "gay");
    list_destroy(ls);
}

Test(list, list_remove_not_found)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");

    cr_assert_not(list_remove_element(ls, "baa",
        (list_find_fn_t*) &my_cstreq).is_some);
    cr_assert_eq(ls->len, 3);
    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "uwu");
    cr_assert_str_eq(list_get(ls, 2).v, "gay");
    list_destroy(ls);
}

Test(list, list_remove_element_first)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");
    OPT(ptr) val = list_remove_element(ls, "owo", (list_find_fn_t*) &my_cstreq);

    cr_assert(val.is_some);
    cr_assert_str_eq(val.v, "owo");
    cr_assert_eq(ls->len, 2);
    cr_assert_str_eq(list_get(ls, 0).v, "uwu");
    cr_assert_str_eq(list_get(ls, 1).v, "gay");
    list_destroy(ls);
}

Test(list, list_remove_element_last)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");
    OPT(ptr) val = list_remove_element(ls, "gay", (list_find_fn_t*) &my_cstreq);

    cr_assert(val.is_some);
    cr_assert_str_eq(val.v, "gay");
    cr_assert_eq(ls->len, 2);
    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "uwu");
    list_destroy(ls);
}

Test(list, list_remove_element_nulcmp)
{
    static const char *UWU = "uwu";
    list_t *ls = list_from(3, "owo", UWU, "gay");

    cr_assert_eq(list_remove_element(ls, (void*) UWU, NULL).v, UWU);
    cr_assert_eq(ls->len, 2);
    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "gay");
    list_destroy(ls);
}

Test(list, list_insert)
{
    list_t *ls = list_from(2, "owo", "gay");

    cr_assert_not(list_insert(ls, 1, "uwu"));
    cr_assert_eq(ls->len, 3);
    cr_assert_str_eq(list_get(ls, 0).v, "owo");
    cr_assert_str_eq(list_get(ls, 1).v, "uwu");
    cr_assert_str_eq(list_get(ls, 2).v, "gay");
    list_destroy(ls);
}

Test(list, list_insert_at_zero)
{
    list_t *ls = list_from(2, "owo", "gay");

    cr_assert_not(list_insert(ls, 0, "uwu"));
    cr_assert_eq(ls->len, 3);
    cr_assert_str_eq(list_get(ls, 0).v, "uwu");
    cr_assert_str_eq(list_get(ls, 1).v, "owo");
    cr_assert_str_eq(list_get(ls, 2).v, "gay");
    list_destroy(ls);
}

Test(list, list_for_each)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");
    int data = 2;

    list_for_each(ls, &for_each_println, &data);
    fflush(stdout);
    cr_assert_stdout_eq_str("owo\nuwu\n");
    list_destroy(ls);
}

Test(list, list_destroy_with)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");
    int data = 2;

    list_destroy_with(ls, &for_each_println, &data);
    fflush(stdout);
    cr_assert_stdout_eq_str("owo\nuwu\n");
}

Test(list, list_find)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");
    list_find_fn_t *find_cb = (list_find_fn_t*) &my_cstreq;

    cr_assert_str_eq(list_find_with(ls, find_cb, "owo").v, "owo");
    cr_assert_str_eq(list_find_with(ls, find_cb, "uwu").v, "uwu");
    cr_assert_str_eq(list_find_with(ls, find_cb, "gay").v, "gay");
    cr_assert_not(list_find_with(ls, find_cb, "baa").is_some);
    list_destroy(ls);
}

Test(list, list_head)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");
    OPT(ptr) head = list_head(ls);

    cr_assert(head.is_some);
    cr_assert_str_eq(head.v, "owo");
}

Test(list, list_tail)
{
    list_t *ls = list_from(3, "owo", "uwu", "gay");
    OPT(ptr) tail = list_tail(ls);

    cr_assert(tail.is_some);
    cr_assert_str_eq(tail.v, "gay");
}
