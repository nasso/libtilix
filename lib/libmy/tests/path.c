/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Unit tests for paths
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "my/path.h"

Test(path, is_abs)
{
    cr_assert_not(my_path_is_abs(my_sstr("")));
    cr_assert_not(my_path_is_abs(my_sstr("./tehio/gsnio")));
    cr_assert_not(my_path_is_abs(my_sstr("gjrieosmgj/geso/../ges.g")));
    cr_assert(my_path_is_abs(my_sstr("/")));
    cr_assert(my_path_is_abs(my_sstr("/gheosgbesogmen/grnqgo/")));
}

Test(path, parent)
{
    OPT(sstr) parent = NONE(sstr);
    const char *parents[][2] = {
        {"/foo/bar", "/foo"},
        {"/foo/bar/", "/foo"},
        {"/", NULL},
        {NULL, NULL},
    };

    for (usize_t i = 0; parents[i][0] != NULL; i++) {
        parent = my_path_parent(my_sstr(parents[i][0]));
        cr_assert_eq(parent.is_some, parents[i][1] != NULL);
        if (parent.is_some)
            cr_assert_str_eq(my_sstr_clone(parent.v), parents[i][1]);
    }
}

Test(path, join)
{
    cr_assert_str_eq(
        my_path_join(my_sstr("/foo/bar"), my_sstr("../cat")),
        "/foo/bar/../cat"
    );
}
