/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON header file
*/

#ifndef LIBJZON_H
#define LIBJZON_H

#include "my/types.h"
#include "my/io/bufreader.h"
#include "my/io/bufwriter.h"
#include "my/collections/hash_map.h"
#include "my/collections/vec.h"

typedef enum {
    JZ_ANY,
    JZ_STR,
    JZ_NUM,
    JZ_OBJ,
    JZ_ARR,
    JZ_BOOL,
    JZ_NULL,
} jzon_type_t;

typedef struct {
    const jzon_type_t type;
    union {
        const hash_map_t *obj;
        const vec_t *arr;
        const char *str;
        f64_t num;
        bool bool_val;
    } u;
} jzon_val_t;

void jzon__val_destroy(jzon_val_t *self);

RC_DEFINE(jzon_val_t, jzon, jzon__val_destroy)

typedef RC(jzon) jzon_t;

jzon_t jzon_create(jzon_type_t type);
jzon_t jzon_create_str(const char *val);
jzon_t jzon_create_num(f64_t val);
jzon_t jzon_create_obj(void);
jzon_t jzon_create_arr(void);
jzon_t jzon_create_bool(bool val);
jzon_t jzon_create_null(void);
jzon_t jzon_from(const char *str);
jzon_t jzon_from_reader(bufreader_t *reader);
jzon_t jzon_from_path(const char *path);
jzon_t jzon_from_file(fd_t fd);
jzon_t jzon_iref(jzon_t self);
void jzon_drop(jzon_t self);
usize_t jzon_len(const jzon_t self);
bool jzon_setq(jzon_t self, const char *query, jzon_t element);
bool jzon_setk(jzon_t self, const char *key, jzon_t element);
bool jzon_seti(jzon_t self, usize_t index, jzon_t element);
jzon_t jzon_getq(const jzon_t self, const char *query);
jzon_t jzon_getk(const jzon_t self, const char *key);
jzon_t jzon_geti(const jzon_t self, usize_t index);
const char *jzon_getq_str(const jzon_t self, const char *query);
const char *jzon_getk_str(const jzon_t self, const char *key);
const char *jzon_geti_str(const jzon_t self, usize_t index);
f64_t jzon_getq_num(const jzon_t self, const char *query);
f64_t jzon_getk_num(const jzon_t self, const char *key);
f64_t jzon_geti_num(const jzon_t self, usize_t index);
jzon_t jzon_getq_obj(const jzon_t self, const char *query);
jzon_t jzon_getk_obj(const jzon_t self, const char *key);
jzon_t jzon_geti_obj(const jzon_t self, usize_t index);
jzon_t jzon_getq_arr(const jzon_t self, const char *query);
jzon_t jzon_getk_arr(const jzon_t self, const char *key);
jzon_t jzon_geti_arr(const jzon_t self, usize_t index);
usize_t jzon_getq_len(const jzon_t self, const char *query);
usize_t jzon_getk_len(const jzon_t self, const char *key);
usize_t jzon_geti_len(const jzon_t self, usize_t index);
bool jzon_getq_bool(const jzon_t self, const char *query);
bool jzon_getk_bool(const jzon_t self, const char *key);
bool jzon_geti_bool(const jzon_t self, usize_t index);
bool jzon_getq_is_null(const jzon_t self, const char *query);
bool jzon_getk_is_null(const jzon_t self, const char *key);
bool jzon_geti_is_null(const jzon_t self, usize_t index);
bool jzon_push(jzon_t self, jzon_t element);
bool jzon_pushi(jzon_t self, usize_t index, jzon_t element);
jzon_t jzon_pop(jzon_t self);
jzon_t jzon_popi(jzon_t self, usize_t index);
const char *jzon_str(const jzon_t self);
bool jzon_set_str(jzon_t self, const char *str);
f64_t jzon_num(const jzon_t self);
bool jzon_set_num(jzon_t self, f64_t val);
bool jzon_bool(const jzon_t self);
bool jzon_set_bool(jzon_t self, bool val);
bool jzon_is_null(const jzon_t jz);

#endif /* LIBJZON_H */
