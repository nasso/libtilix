/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Vector tests
*/

#include <criterion/criterion.h>
#include "my/collections/vector.h"

Test(vector, vector_new, .timeout = 1.0)
{
    vector_t *v = vector_new(sizeof(int));

    cr_assert_eq(v->len, 0);
    cr_assert_eq(v->stride, sizeof(int));
    vector_destroy(v);
}

Test(vector, vector_from, .timeout = 1.0)
{
    const int data[3] = {6, 2, 1};
    vector_t *v = vector_from(sizeof(int), 3, data);

    cr_assert_eq(v->len, 3);
    cr_assert_geq(v->capacity, 3);
    cr_assert_eq(v->stride, sizeof(int));
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 0), 6);
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 1), 2);
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 2), 1);
    vector_destroy(v);
}

Test(vector, vector_with_capacity, .timeout = 1.0)
{
    vector_t *v = vector_with_capacity(sizeof(int), 20);

    cr_assert_eq(v->len, 0);
    cr_assert_eq(v->capacity, 20);
    cr_assert_eq(v->stride, sizeof(int));
    vector_destroy(v);
}

Test(vector, vector_reserve_on_empty, .timeout = 1.0)
{
    vector_t *v = vector_with_capacity(sizeof(int), 10);

    cr_assert_eq(v->len, 0);
    cr_assert_eq(v->capacity, 10);
    cr_assert_eq(v->stride, sizeof(int));
    vector_reserve(v, 5);
    cr_assert_eq(v->len, 0);
    cr_assert_eq(v->capacity, 10);
    cr_assert_eq(v->stride, sizeof(int));
    vector_reserve(v, 15);
    cr_assert_eq(v->len, 0);
    cr_assert_geq(v->capacity, 15);
    cr_assert_eq(v->stride, sizeof(int));
    vector_destroy(v);
}

Test(vector, vector_reserve_on_non_empty, .timeout = 1.0)
{
    const int data[3] = {6, 2, 1};
    vector_t *v = vector_from(sizeof(int), 3, data);

    cr_assert_eq(v->len, 3);
    cr_assert_geq(v->capacity, 3);
    cr_assert_eq(v->stride, sizeof(int));
    vector_reserve(v, 5);
    cr_assert_eq(v->len, 3);
    cr_assert_geq(v->capacity, 8);
    cr_assert_eq(v->stride, sizeof(int));
    vector_reserve(v, 64);
    cr_assert_eq(v->len, 3);
    cr_assert_geq(v->capacity, 67);
    cr_assert_eq(v->stride, sizeof(int));
    vector_destroy(v);
}

Test(vector, vector_get, .timeout = 1.0)
{
    const int data[3] = {6, 2, 1};
    vector_t *v = vector_from(sizeof(int), 3, data);

    cr_assert_eq(v->len, 3);
    cr_assert_geq(v->capacity, 3);
    cr_assert_eq(v->stride, sizeof(int));
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 0), 6);
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 1), 2);
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 2), 1);
    vector_destroy(v);
}

Test(vector, vector_set, .timeout = 1.0)
{
    const int data[3] = {6, 2, 1};
    static const int FOURTY_TWO = 42;
    vector_t *v = vector_from(sizeof(int), 3, data);

    vector_set(v, 1, &FOURTY_TWO);
    cr_assert_eq(v->len, 3);
    cr_assert_geq(v->capacity, 3);
    cr_assert_eq(v->stride, sizeof(int));
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 0), 6);
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 1), 42);
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 2), 1);
    vector_destroy(v);
}

Test(vector, vector_push, .timeout = 1.0)
{
    const int data[3] = {6, 2, 1};
    vector_t *v = vector_new(sizeof(int));

    vector_push(v, &data[0]);
    vector_push(v, &data[1]);
    vector_push(v, &data[2]);
    cr_assert_eq(v->len, 3);
    cr_assert_geq(v->capacity, 3);
    cr_assert_eq(v->stride, sizeof(int));
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 1), 2);
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 0), 6);
    cr_assert_eq(*VECTOR_GET_AS(int*, v, 2), 1);
    vector_destroy(v);
}

Test(vector, vector_pop, .timeout = 1.0)
{
    const int data[3] = {6, 2, 1};
    vector_t *v = vector_from(sizeof(int), 3, data);

    cr_assert_eq(v->len, 3);
    cr_assert_geq(v->capacity, 3);
    cr_assert_eq(v->stride, sizeof(int));
    cr_assert_eq(*VECTOR_POP_AS(int*, v), 1);
    cr_assert_eq(v->len, 2);
    cr_assert_geq(v->capacity, 3);
    cr_assert_eq(v->stride, sizeof(int));
    cr_assert_eq(*VECTOR_POP_AS(int*, v), 2);
    cr_assert_eq(v->len, 1);
    cr_assert_geq(v->capacity, 3);
    cr_assert_eq(v->stride, sizeof(int));
    cr_assert_eq(*VECTOR_POP_AS(int*, v), 6);
    cr_assert_eq(v->len, 0);
    cr_assert_geq(v->capacity, 3);
    cr_assert_eq(v->stride, sizeof(int));
    vector_destroy(v);
}
