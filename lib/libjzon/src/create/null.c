/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON create_bool conbooluctor
*/

#include "my/my.h"
#include "jzon/jzon.h"

jzon_t jzon_create_null(void)
{
    return (jzon_create(JZ_NULL));
}
