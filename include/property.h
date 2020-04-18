/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Tiled "custom properties"
*/

#ifndef LIBTILIX_PROPERTY_H
#define LIBTILIX_PROPERTY_H

#include "my/types.h"
#include "jzon/deser.h"

typedef enum {
    TL_STRING,
    TL_INT,
    TL_FLOAT,
    TL_BOOL,
    TL_COLOR,
    TL_FILE,
} tl_property_type_t;

typedef union {
    char *str;
    i64_t i;
    f64_t f;
    bool b;
    u32_t color;
    char *file;
} tl_property_value_t;

extern const jzon_type_desc_t TL_PROPERTY_VALUE_TYPE_DESC;

typedef struct {
    char *name;
    tl_property_type_t type;
    tl_property_value_t u;
} tl_property_t;

OPT_DEFINE(tl_property_t, tl_property)

extern const jzon_type_desc_t TL_PROPERTY_TYPE_DESC;
extern const jzon_type_desc_t TL_PROPERTIES_TYPE_DESC;

#endif /* LIBTILIX_PROPERTY_H */
