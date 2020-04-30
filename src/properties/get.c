/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Properties fetching
*/

#include "my/my.h"
#include "tilix/property.h"

const tl_property_t *tl_properties_get(const tl_properties_t *self,
    const char *name)
{
    for (usize_t i = 0; i < self->len; i++) {
        if (my_cstreq(self->data[i].name, name))
            return (&self->data[i]);
    }
    return (NULL);
}

const char *tl_properties_get_str(const tl_properties_t *self,
    const char *name)
{
    const tl_property_t *prop = tl_properties_get(self, name);

    if (prop == NULL || prop->type != TL_STRING)
        return (NULL);
    return (prop->u.str);
}

const char *tl_properties_get_file(const tl_properties_t *self,
    const char *name)
{
    const tl_property_t *prop = tl_properties_get(self, name);

    if (prop == NULL || prop->type != TL_FILE)
        return (NULL);
    return (prop->u.file);
}
