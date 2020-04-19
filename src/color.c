/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Color parser
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"
#include "tilix/common.h"

static const char *MIXED_HEX = "0123456789ABCDEFabcdef";
static const char *UPPER_HEX = "0123456789ABCDEF";
static const char *LOWER_HEX = "0123456789abcdef";

static bool is_hexa_str(const char *str)
{
    for (usize_t i = 0; str[i]; i++) {
        if (my_cstrchr(MIXED_HEX, str[i]) == NULL)
            return (false);
    }
    return (true);
}

static u32_t parse_hex(const char *str)
{
    u32_t digit = 0;
    u32_t val = 0;

    for (usize_t i = 0; str[i]; i++) {
        if (my_cstrchr(UPPER_HEX, str[i]))
            digit = my_cstrchr(UPPER_HEX, str[i]) - UPPER_HEX;
        else
            digit = my_cstrchr(LOWER_HEX, str[i]) - LOWER_HEX;
        val = val * 0x10 + digit;
    }
    return (val);
}

static bool parse_color(const jzon_t jz, const jzon_deser_params_t *params,
    void *ptr)
{
    u32_t *dest = ptr;
    const char *str = jzon_str(jz);

    (void)(params);
    if (str[0] != '#' || !is_hexa_str(str + 1))
        return (true);
    switch (my_cstrlen(str)) {
    default:
        return (true);
    case 7:
        *dest = 0xFF000000 + parse_hex(str + 1);
        break;
    case 9:
        *dest = parse_hex(str + 1);
        break;
    }
    return (false);
}

const jzon_type_desc_t TL_COLOR_STR_TYPE_DESC = {
    .primitive = JZ_STR,
    .size = sizeof(u32_t),
    .deser_func = &parse_color,
};
