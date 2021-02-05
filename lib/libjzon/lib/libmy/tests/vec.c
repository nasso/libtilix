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
#include "my/collections/vec.h"

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

TestSuite(vec, .timeout = 1.0, .init = redirect_all);

Test(vec, vec_new)
{
    vec_t *vec = vec_new();

    cr_assert(vec != NULL);
    cr_assert_eq(vec->len, 0);
    vec_destroy(vec);
}

Test(vec, vec_from)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    cr_assert_eq(vec->len, 3);
    cr_assert_str_eq(vec->data[0], "owo");
    cr_assert_str_eq(vec->data[1], "uwu");
    cr_assert_str_eq(vec->data[2], "gay");
    vec_destroy(vec);
}

Test(vec, vec_from_arr)
{
    const char *data[3] = {"owo", "uwu", "gay"};
    vec_t *vec = vec_from_arr(3, (void**) data);

    cr_assert_eq(vec->len, 3);
    cr_assert_str_eq(vec->data[0], "owo");
    cr_assert_str_eq(vec->data[1], "uwu");
    cr_assert_str_eq(vec->data[2], "gay");
    vec_destroy(vec);
}

Test(vec, vec_clear)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    vec_clear(vec);
    cr_assert_eq(vec->len, 0);
    vec_destroy(vec);
}

Test(vec, vec_clear_and_reinstert)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    vec_clear(vec);
    cr_assert_not(vec_push(vec, "owo"));
    cr_assert_eq(vec->len, 1);
    cr_assert_str_eq(vec->data[0], "owo");
    vec_destroy(vec);
}

Test(vec, vec_push_back)
{
    vec_t *vec = vec_new();

    cr_assert_not(vec_push(vec, "owo"));
    cr_assert_not(vec_push(vec, "uwu"));
    cr_assert_not(vec_push(vec, "gay"));
    cr_assert_eq(vec->len, 3);
    cr_assert_str_eq(vec->data[0], "owo");
    cr_assert_str_eq(vec->data[1], "uwu");
    cr_assert_str_eq(vec->data[2], "gay");
    vec_destroy(vec);
}

Test(vec, vec_pop)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(vec_pop(vec).v, "gay");
    cr_assert_eq(vec->len, 2);
    cr_assert_str_eq(vec->data[0], "owo");
    cr_assert_str_eq(vec->data[1], "uwu");
    vec_destroy(vec);
}

Test(vec, vec_get)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "uwu");
    cr_assert_str_eq(vec_get(vec, 2).v, "gay");
    cr_assert_not(vec_get(vec, 3).is_some);
    vec_destroy(vec);
}

Test(vec, vec_set)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    cr_assert(vec_set(vec, 1, "baa").is_some);
    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "baa");
    cr_assert_str_eq(vec_get(vec, 2).v, "gay");
    vec_destroy(vec);
}

Test(vec, vec_remove)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(vec_remove(vec, 1).v, "uwu");
    cr_assert_eq(vec->len, 2);
    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "gay");
    vec_destroy(vec);
}

Test(vec, vec_remove_out_of_bounds)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    cr_assert_not(vec_remove(vec, 3).is_some);
    cr_assert_eq(vec->len, 3);
    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "uwu");
    cr_assert_str_eq(vec_get(vec, 2).v, "gay");
    vec_destroy(vec);
}

Test(vec, vec_remove_first)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(vec_remove(vec, 0).v, "owo");
    cr_assert_eq(vec->len, 2);
    cr_assert_str_eq(vec_get(vec, 0).v, "uwu");
    cr_assert_str_eq(vec_get(vec, 1).v, "gay");
    vec_destroy(vec);
}

Test(vec, vec_remove_last)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    cr_assert_str_eq(vec_remove(vec, 2).v, "gay");
    cr_assert_eq(vec->len, 2);
    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "uwu");
    vec_destroy(vec);
}

Test(vec, vec_remove_element)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");
    OPT(ptr) val = vec_remove_element(vec, "uwu", (vec_find_fn_t*) &my_cstreq);

    cr_assert(val.is_some);
    cr_assert_str_eq(val.v, "uwu");
    cr_assert_eq(vec->len, 2);
    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "gay");
    vec_destroy(vec);
}

Test(vec, vec_remove_not_found)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");

    cr_assert_not(vec_remove_element(vec, "baa",
        (vec_find_fn_t*) &my_cstreq).is_some);
    cr_assert_eq(vec->len, 3);
    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "uwu");
    cr_assert_str_eq(vec_get(vec, 2).v, "gay");
    vec_destroy(vec);
}

Test(vec, vec_remove_element_first)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");
    OPT(ptr) val = vec_remove_element(vec, "owo", (vec_find_fn_t*) &my_cstreq);

    cr_assert(val.is_some);
    cr_assert_str_eq(val.v, "owo");
    cr_assert_eq(vec->len, 2);
    cr_assert_str_eq(vec_get(vec, 0).v, "uwu");
    cr_assert_str_eq(vec_get(vec, 1).v, "gay");
    vec_destroy(vec);
}

Test(vec, vec_remove_element_last)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");
    OPT(ptr) val = vec_remove_element(vec, "gay", (vec_find_fn_t*) &my_cstreq);

    cr_assert(val.is_some);
    cr_assert_str_eq(val.v, "gay");
    cr_assert_eq(vec->len, 2);
    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "uwu");
    vec_destroy(vec);
}

Test(vec, vec_remove_element_nulcmp)
{
    static const char *UWU = "uwu";
    vec_t *vec = vec_from(3, "owo", UWU, "gay");

    cr_assert_eq(vec_remove_element(vec, (void*) UWU, NULL).v, UWU);
    cr_assert_eq(vec->len, 2);
    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "gay");
    vec_destroy(vec);
}

Test(vec, vec_insert)
{
    vec_t *vec = vec_from(2, "owo", "gay");

    cr_assert_not(vec_insert(vec, 1, "uwu"));
    cr_assert_eq(vec->len, 3);
    cr_assert_str_eq(vec_get(vec, 0).v, "owo");
    cr_assert_str_eq(vec_get(vec, 1).v, "uwu");
    cr_assert_str_eq(vec_get(vec, 2).v, "gay");
    vec_destroy(vec);
}

Test(vec, vec_for_each)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");
    int data = 2;

    vec_for_each(vec, &for_each_println, &data);
    fflush(stdout);
    cr_assert_stdout_eq_str("owo\nuwu\n");
    vec_destroy(vec);
}

Test(vec, vec_destroy_with)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");
    int data = 2;

    vec_destroy_with(vec, &for_each_println, &data);
    fflush(stdout);
    cr_assert_stdout_eq_str("owo\nuwu\n");
}

Test(vec, vec_find)
{
    vec_t *vec = vec_from(3, "owo", "uwu", "gay");
    vec_find_fn_t *find_cb = (vec_find_fn_t*) &my_cstreq;

    cr_assert_str_eq(vec_find_with(vec, find_cb, "owo").v, "owo");
    cr_assert_str_eq(vec_find_with(vec, find_cb, "uwu").v, "uwu");
    cr_assert_str_eq(vec_find_with(vec, find_cb, "gay").v, "gay");
    cr_assert_not(vec_find_with(vec, find_cb, "baa").is_some);
    vec_destroy(vec);
}
