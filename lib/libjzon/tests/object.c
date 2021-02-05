/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON objects unit tests
*/

#include <criterion/criterion.h>
#include "jzon/jzon.h"

Test(objects, get_set_key)
{
    jzon_t jz = jzon_create_obj();
    jzon_t element = NULL;

    cr_assert_not(jzon_setk(jz, "foo", jzon_create_str("bar")));
    element = jzon_getk(jz, "foo");
    cr_assert_not_null(element);
    cr_assert_str_eq(jzon_str(element), "bar");
    jzon_drop(jz);
}
