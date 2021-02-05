/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Deserializing utilities
*/

#ifndef JZON_DESER_H
#define JZON_DESER_H

#include "my/types.h"
#include "my/io/bufreader.h"
#include "jzon/jzon.h"

#ifndef JZON_DESER_MAX_FIELD_COUNT
    #define JZON_DESER_MAX_FIELD_COUNT 128
#endif

#ifndef JZON_DESER_MAX_ENUM_SIZE
    #define JZON_DESER_MAX_ENUM_SIZE 32
#endif

typedef struct jzon_type_desc jzon_type_desc_t;

typedef struct {
    usize_t max_size;
    usize_t min_size;
    const jzon_type_desc_t *item_type;
    struct {
        const char *str_val;
        i32_t enum_val;
    } str_enum[JZON_DESER_MAX_ENUM_SIZE];
    void *user_data;
} jzon_deser_params_t;

typedef bool (jzon_deser_fn_t)(const jzon_t jz,
    const jzon_deser_params_t *params, void *dest);

typedef jzon_t (jzon_deser_default_fn_t)(const jzon_t jz,
    const jzon_deser_params_t *params);

typedef struct {
    const char *match;
    bool optional;
    const char *default_json;
    jzon_deser_default_fn_t *default_func;
    usize_t offset;
    const jzon_type_desc_t *type;
    jzon_deser_params_t params;
} jzon_deser_field_t;

struct jzon_type_desc {
    jzon_type_t primitive;
    jzon_deser_fn_t *deser_func;
    usize_t size;
    bool is_ptr;
    jzon_deser_field_t fields[JZON_DESER_MAX_FIELD_COUNT];
};

extern const jzon_type_desc_t JZON_IS_SOME_TYPE_DESC;
extern const jzon_type_desc_t JZON_IS_NONE_TYPE_DESC;
extern const jzon_type_desc_t JZON_HASH_MAP_TYPE_DESC;
extern const jzon_type_desc_t JZON_ARR_SIZE_TYPE_DESC;
extern const jzon_type_desc_t JZON_PLAIN_ARR_TYPE_DESC;
extern const jzon_type_desc_t JZON_HEAP_ARR_TYPE_DESC;
extern const jzon_type_desc_t JZON_ENUM_TYPE_DESC;
extern const jzon_type_desc_t JZON_STR_TYPE_DESC;
extern const jzon_type_desc_t JZON_BOOL_TYPE_DESC;
extern const jzon_type_desc_t JZON_U8_TYPE_DESC;
extern const jzon_type_desc_t JZON_U16_TYPE_DESC;
extern const jzon_type_desc_t JZON_U32_TYPE_DESC;
extern const jzon_type_desc_t JZON_U64_TYPE_DESC;
extern const jzon_type_desc_t JZON_USIZE_TYPE_DESC;
extern const jzon_type_desc_t JZON_I8_TYPE_DESC;
extern const jzon_type_desc_t JZON_I16_TYPE_DESC;
extern const jzon_type_desc_t JZON_I32_TYPE_DESC;
extern const jzon_type_desc_t JZON_I64_TYPE_DESC;
extern const jzon_type_desc_t JZON_ISIZE_TYPE_DESC;
extern const jzon_type_desc_t JZON_F32_TYPE_DESC;
extern const jzon_type_desc_t JZON_F64_TYPE_DESC;

bool jzon_deser_path(const char *path, const jzon_type_desc_t *type_desc,
    const jzon_deser_params_t *params, void *dest);
bool jzon_deser_file(fd_t fd, const jzon_type_desc_t *type_desc,
    const jzon_deser_params_t *params, void *dest);
bool jzon_deser_cstr(const char *str, const jzon_type_desc_t *type_desc,
    const jzon_deser_params_t *params, void *dest);
bool jzon_deser_reader(bufreader_t *reader, const jzon_type_desc_t *type_desc,
    const jzon_deser_params_t *params, void *dest);
bool jzon_deser(const jzon_t jz, const jzon_type_desc_t *type_desc,
    const jzon_deser_params_t *params, void *dest);

#endif /* JZON_DESER_H */
