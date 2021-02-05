/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON arrays tests
*/

#include <criterion/criterion.h>
#include "jzon/jzon.h"

static void assert_num_at(jzon_t jz, usize_t i, f64_t num)
{
    jzon_t val = NULL;

    val = jzon_geti(jz, i);
    cr_assert_not_null(val);
    cr_assert(val->v->type == JZ_NUM && val->v->u.num == num);
}

Test(arrays, push)
{
    jzon_t jz = jzon_create_arr();

    cr_assert_not(jzon_push(jz, jzon_create_num(35)));
    cr_assert_not(jzon_push(jz, jzon_create_num(5.8)));
    cr_assert_not(jzon_push(jz, jzon_create_num(420)));
    cr_assert_eq(jzon_len(jz), 3);
    assert_num_at(jz, 0, 35);
    assert_num_at(jz, 1, 5.8);
    assert_num_at(jz, 2, 420);
    jzon_drop(jz);
}

Test(arrays, pushi)
{
    jzon_t jz = jzon_create_arr();

    cr_assert_not(jzon_push(jz, jzon_create_num(35)));
    cr_assert_not(jzon_pushi(jz, 0, jzon_create_num(5.8)));
    cr_assert_not(jzon_pushi(jz, 1, jzon_create_num(420)));
    cr_assert_eq(jzon_len(jz), 3);
    assert_num_at(jz, 0, 5.8);
    assert_num_at(jz, 1, 420);
    assert_num_at(jz, 2, 35);
    jzon_drop(jz);
}

Test(arrays, pop)
{
    jzon_t jz = jzon_create_arr();
    jzon_t element = NULL;

    cr_assert_not(jzon_push(jz, jzon_create_num(35)));
    cr_assert_not(jzon_push(jz, jzon_create_num(5.8)));
    cr_assert_not(jzon_push(jz, jzon_create_num(420)));
    element = jzon_pop(jz);
    cr_assert_eq(jzon_len(jz), 2);
    assert_num_at(jz, 0, 35);
    assert_num_at(jz, 1, 5.8);
    jzon_drop(jz);
    cr_assert_not_null(element);
    cr_assert_eq(element->v->type, JZ_NUM);
    cr_assert_eq(element->v->u.num, 420);
    jzon_drop(element);
}

Test(arrays, popi)
{
    jzon_t jz = jzon_create_arr();
    jzon_t element = NULL;

    cr_assert_not(jzon_push(jz, jzon_create_num(35)));
    cr_assert_not(jzon_push(jz, jzon_create_num(5.8)));
    cr_assert_not(jzon_push(jz, jzon_create_num(420)));
    element = jzon_popi(jz, 1);
    cr_assert_eq(jzon_len(jz), 2);
    assert_num_at(jz, 0, 35);
    assert_num_at(jz, 1, 420);
    jzon_drop(jz);
    cr_assert_not_null(element);
    cr_assert_eq(element->v->type, JZ_NUM);
    cr_assert_eq(element->v->u.num, 5.8);
    jzon_drop(element);
}
