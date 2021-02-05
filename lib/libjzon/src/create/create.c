/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON constructor
*/

#include "my/my.h"
#include "jzon/jzon.h"

jzon_t jzon_create(jzon_type_t type)
{
    jzon_val_t *self = my_calloc(1, sizeof(jzon_val_t));

    if (self == NULL)
        return (NULL);
    *((jzon_type_t*) &self->type) = type;
    return (RC_WRAP(jzon)(self));
}
