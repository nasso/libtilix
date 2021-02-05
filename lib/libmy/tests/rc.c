/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** reference counting tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my/my.h"
#include "my/io.h"

static u32_t *mk32(u32_t v)
{
    u32_t *box = my_malloc(sizeof(u32_t));

    *box = v;
    return (box);
}

static void loud_free(u32_t *v)
{
    my_printf("free %d;", *v);
    free(v);
}

RC_DEFINE(u32_t, test, loud_free)

TestSuite(rc, .timeout = 1.0, .init = cr_redirect_stdout);

Test(rc, one_user)
{
    RC(test) ptr = RC_WRAP(test)(mk32(42));

    my_printf("a;");
    cr_assert_eq(*ptr->v, 42);
    my_printf("b;");
    RC_DROP(test)(ptr);
    my_printf("c;");
    cr_assert_stdout_eq_str("a;b;free 42;c;");
}

Test(rc, shared_users)
{
    RC(test) ptr = RC_WRAP(test)(mk32(42));
    RC(test) ptr2 = NULL;

    my_printf("a;");
    ptr2 = RC_INC(test)(ptr);
    my_printf("b;");
    RC_DROP(test)(ptr);
    my_printf("c;");
    RC_DROP(test)(ptr2);
    my_printf("d;");
    cr_assert_stdout_eq_str("a;b;c;free 42;d;");
}

Test(rc, one_weak)
{
    RC(test) ptr = RC_WRAP(test)(mk32(42));
    WRC(test) wptr = NULL;

    my_printf("a;");
    wptr = RC_WEAK(test)(ptr);
    my_printf("b;");
    cr_assert(WRC_ALIVE(test)(wptr));
    RC_DROP(test)(ptr);
    my_printf("c;");
    cr_assert_not(WRC_ALIVE(test)(wptr));
    my_printf("d;");
    WRC_DROP(test)(wptr);
    my_printf("e;");
    cr_assert_stdout_eq_str("a;b;free 42;c;d;e;");
}
