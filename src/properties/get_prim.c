/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Properties fetching (primitive types)
*/

#include "my/my.h"
#include "tilix/property.h"

i64_t tl_properties_get_i64(const tl_properties_t *self, const char *name)
{
    const tl_property_t *prop = tl_properties_get(self, name);

    if (prop == NULL || prop->type != TL_INT)
        return (0);
    return (prop->u.i);
}

f64_t tl_properties_get_f64(const tl_properties_t *self, const char *name)
{
    const tl_property_t *prop = tl_properties_get(self, name);

    if (prop == NULL || prop->type != TL_FLOAT)
        return (0);
    return (prop->u.f);
}

bool tl_properties_get_bool(const tl_properties_t *self, const char *name)
{
    const tl_property_t *prop = tl_properties_get(self, name);

    if (prop == NULL || prop->type != TL_BOOL)
        return (false);
    return (prop->u.b);
}

u32_t tl_properties_get_color(const tl_properties_t *self, const char *name)
{
    const tl_property_t *prop = tl_properties_get(self, name);

    if (prop == NULL || prop->type != TL_COLOR)
        return (0);
    return (prop->u.color);
}
