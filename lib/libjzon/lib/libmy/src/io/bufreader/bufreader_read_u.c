/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Buffered reader
*/

#include "my/my.h"
#include "my/io.h"

OPT(u8) bufreader_read_u8(bufreader_t *self)
{
    u8_t value = 0;
    OPT(usize) bytes_read = bufreader_read(self, &value, sizeof(u8_t));

    if (bytes_read.is_some)
        return (SOME(u8, value));
    return (NONE(u8));
}

OPT(u16) bufreader_read_u16(bufreader_t *self)
{
    u16_t value = 0;
    OPT(usize) bytes_read = bufreader_read(self, &value, sizeof(u16_t));

    if (bytes_read.is_some)
        return (SOME(u16, value));
    return (NONE(u16));
}

OPT(u32) bufreader_read_u32(bufreader_t *self)
{
    u32_t value = 0;
    OPT(usize) bytes_read = bufreader_read(self, &value, sizeof(u32_t));

    if (bytes_read.is_some)
        return (SOME(u32, value));
    return (NONE(u32));
}

OPT(u64) bufreader_read_u64(bufreader_t *self)
{
    u64_t value = 0;
    OPT(usize) bytes_read = bufreader_read(self, &value, sizeof(u64_t));

    if (bytes_read.is_some)
        return (SOME(u64, value));
    return (NONE(u64));
}

OPT(usize) bufreader_read_usize(bufreader_t *self)
{
    usize_t value = 0;
    OPT(usize) bytes_read = bufreader_read(self, &value, sizeof(usize_t));

    if (bytes_read.is_some)
        return (SOME(usize, value));
    return (NONE(usize));
}
