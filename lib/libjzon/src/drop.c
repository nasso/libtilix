/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_drop implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

void jzon_drop(jzon_t self)
{
    RC_DROP(jzon)(self);
}
