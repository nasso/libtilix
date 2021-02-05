/*
** EPITECH PROJECT, 2020
** libtilix
** File description:
** Tiled template
*/

#ifndef LIBTILIX_TEMPLATE_H
#define LIBTILIX_TEMPLATE_H

#include "my/types.h"
#include "jzon/deser.h"
#include "tilix/object.h"
#include "tilix/tileset.h"

typedef struct {
    OPT(tl_tileset) tileset;
    tl_object_t object;
} tl_object_template_t;

OPT_DEFINE(tl_object_template_t, tl_object_template)

extern const jzon_type_desc_t TL_OBJECT_TEMPLATE_TYPE_DESC;

void tl_object_template_deinit(tl_object_template_t *self);

#endif /* LIBTILIX_TEMPLATE_H */
