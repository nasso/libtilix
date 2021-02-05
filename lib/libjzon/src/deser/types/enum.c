/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON enum deserializers
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool jzon_deser_enum(const jzon_t jz, const jzon_deser_params_t *params,
    void *dest)
{
    const char *str = jzon_str(jz);
    i32_t *dest_ptr = dest;

    if (str == NULL)
        return (true);
    for (usize_t i = 0; params->str_enum[i].str_val; i++) {
        if (my_cstreq(params->str_enum[i].str_val, str)) {
            *dest_ptr = params->str_enum[i].enum_val;
            return (false);
        }
    }
    return (true);
}

const jzon_type_desc_t JZON_ENUM_TYPE_DESC = {
    .primitive = JZ_STR,
    .deser_func = &jzon_deser_enum,
    .size = sizeof(i32_t),
};
