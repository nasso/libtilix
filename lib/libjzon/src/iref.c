/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_take implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

jzon_t jzon_iref(jzon_t self)
{
    return (RC_INC(jzon)(self));
}
