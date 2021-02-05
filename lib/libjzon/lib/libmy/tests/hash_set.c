/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** hash_set tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "my/io.h"
#include "my/hash.h"
#include "my/collections/hash_set.h"
#include "my/collections/list.h"

static OPT(i32) put_in_list(void *user_data, void *element)
{
    list_t *ls = user_data;

    list_push_back(ls, element);
    return (NONE(i32));
}

static char *randstr(usize_t n)
{
    char *str = my_calloc(sizeof(char), n + 1);

    for (usize_t i = 0; i < n; i++)
        str[i] = 'a' + (rand() % 26);
    str[n] = '\0';
    return (str);
}

Test(hash_set, new)
{
    hash_set_t *set = hash_set_with_eq((hash_set_hash_fn_t*) &my_sdbm_cstr,
        (bool (*)(const void*, const void*)) &my_cstreq);

    cr_assert_not_null(set);
}

Test(hash_set, destroy)
{
    hash_set_t *set = hash_set_new((hash_set_hash_fn_t*) &my_sdbm_cstr);

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    hash_set_destroy(set);
}

Test(hash_set, insert)
{
    hash_set_t *set = hash_set_new((hash_set_hash_fn_t*) &my_sdbm_cstr);

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    cr_assert_not(hash_set_insert(set, "foo"));
    cr_assert_not(hash_set_insert(set, "bar"));
    hash_set_destroy(set);
}

Test(hash_set, insert_exists_already)
{
    hash_set_t *set = hash_set_new((hash_set_hash_fn_t*) &my_sdbm_cstr);

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    cr_assert_not(hash_set_insert(set, "foo"));
    cr_assert(hash_set_has(set, "foo"));
    cr_assert_not(hash_set_insert(set, "bar"));
    cr_assert(hash_set_has(set, "foo"));
    cr_assert(hash_set_has(set, "bar"));
    hash_set_destroy(set);
}

Test(hash_set, has)
{
    hash_set_t *set = hash_set_new((hash_set_hash_fn_t*) &my_sdbm_cstr);

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    cr_assert_not(hash_set_has(set, "foo"));
    hash_set_insert(set, "foo");
    cr_assert(hash_set_has(set, "foo"));
    cr_assert_not(hash_set_has(set, "bar"));
    hash_set_insert(set, "bar");
    cr_assert(hash_set_has(set, "foo"));
    cr_assert(hash_set_has(set, "bar"));
    hash_set_destroy(set);
}

Test(hash_set, insert_all)
{
    hash_set_t *set = hash_set_new((hash_set_hash_fn_t*) &my_sdbm_cstr);

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    hash_set_insert_all(set, 2, "foo", "bar");
    cr_assert(hash_set_has(set, "foo"));
    cr_assert(hash_set_has(set, "bar"));
    hash_set_destroy(set);
}

Test(hash_set, insert_all_arr)
{
    hash_set_t *set = hash_set_new((hash_set_hash_fn_t*) &my_sdbm_cstr);
    char *const values[2] = {"foo", "bar"};

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    hash_set_insert_all_arr(set, 2, (void**) values);
    cr_assert(hash_set_has(set, "foo"));
    cr_assert(hash_set_has(set, "bar"));
    hash_set_destroy(set);
}

Test(hash_set, from_arr)
{
    char *const values[2] = {"foo", "bar"};
    hash_set_t *set = hash_set_from_arr((hash_set_hash_fn_t*) &my_sdbm_cstr, 2,
        (void *const*) values);

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    cr_assert(hash_set_has(set, "foo"));
    cr_assert(hash_set_has(set, "bar"));
    hash_set_destroy(set);
}

Test(hash_set, remove)
{
    hash_set_t *set = hash_set_from((hash_set_hash_fn_t*) &my_sdbm_cstr, 2,
        "foo", "bar");

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    cr_assert_str_eq(hash_set_remove(set, "foo"), "foo");
    cr_assert_not(hash_set_has(set, "foo"));
    cr_assert(hash_set_has(set, "bar"));
    hash_set_destroy(set);
}

Test(hash_set, clear)
{
    hash_set_t *set = hash_set_from((hash_set_hash_fn_t*) &my_sdbm_cstr, 2,
        "foo", "bar");

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    hash_set_clear(set);
    cr_assert_not(hash_set_has(set, "foo"));
    cr_assert_not(hash_set_has(set, "bar"));
    hash_set_destroy(set);
}

Test(hash_set, for_each)
{
    list_t *ls = list_new();
    hash_set_t *set = hash_set_from((hash_set_hash_fn_t*) &my_sdbm_cstr, 2,
        "foo", "bar");

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    hash_set_for_each(set, &put_in_list, ls);
    hash_set_destroy(set);
    cr_assert_eq(ls->len, 2);
    cr_assert(list_find_with(ls, (list_find_fn_t*) &my_cstreq, "foo").is_some);
    cr_assert(list_find_with(ls, (list_find_fn_t*) &my_cstreq, "bar").is_some);
}

Test(hash_set, clear_with)
{
    list_t *ls = list_new();
    hash_set_t *set = hash_set_from((hash_set_hash_fn_t*) &my_sdbm_cstr, 2,
        "foo", "bar");

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    hash_set_clear_with(set, &put_in_list, ls);
    cr_assert_not(hash_set_has(set, "foo"));
    cr_assert_not(hash_set_has(set, "bar"));
    hash_set_destroy(set);
    cr_assert_eq(ls->len, 2);
    cr_assert(list_find_with(ls, (list_find_fn_t*) &my_cstreq, "foo").is_some);
    cr_assert(list_find_with(ls, (list_find_fn_t*) &my_cstreq, "bar").is_some);
}

Test(hash_set, destroy_with)
{
    list_t *ls = list_new();
    hash_set_t *set = hash_set_from((hash_set_hash_fn_t*) &my_sdbm_cstr, 2,
        "foo", "bar");

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    hash_set_destroy_with(set, &put_in_list, ls);
    cr_assert_eq(ls->len, 2);
    cr_assert(list_find_with(ls, (list_find_fn_t*) &my_cstreq, "foo").is_some);
    cr_assert(list_find_with(ls, (list_find_fn_t*) &my_cstreq, "bar").is_some);
}

Test(hash_set, lots_of_values)
{
    char *tmp = NULL;
    char *values[10000] = {NULL};
    hash_set_t *set = hash_set_new((hash_set_hash_fn_t*) &my_sdbm_cstr);

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    for (usize_t i = 0; i < 10000; i++) {
        tmp = randstr(64);
        values[i] = my_format("%zu-%s", i, tmp);
        my_free(tmp);
        cr_assert_not(hash_set_insert(set, values[i]));
    }
    cr_assert_leq((double) set->size / (double) set->bucket_count, 1.0);
    for (usize_t i = 0; i < 10000; i++)
        cr_assert(hash_set_has(set, values[i]));
    for (usize_t i = 0; i < 10000; i++)
        my_free(values[i]);
    hash_set_destroy(set);
}

Test(hash_set, clone)
{
    hash_set_t *set = hash_set_from((hash_set_hash_fn_t*) &my_sdbm_cstr, 2,
        "foo", "bar");
    hash_set_t *clone = NULL;

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    clone = hash_set_clone(set);
    cr_assert(hash_set_has(clone, "foo"));
    cr_assert(hash_set_has(clone, "bar"));
    hash_set_destroy(set);
}

Test(hash_set, clone_with)
{
    hash_set_t *set = hash_set_from((hash_set_hash_fn_t*) &my_sdbm_cstr, 2,
        "foo", "bar");
    hash_set_t *clone = NULL;

    set->eq = (bool (*)(const void*, const void*)) &my_cstreq;
    clone = hash_set_clone_with(set, (void *(*)(const void*)) &my_cstrdup,
        &my_free);
    cr_assert(hash_set_has(clone, "foo"));
    cr_assert(hash_set_has(clone, "bar"));
    hash_set_destroy(set);
}
