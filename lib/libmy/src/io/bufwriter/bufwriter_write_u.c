/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Buffered writer
*/

#include "my/my.h"
#include "my/io.h"

OPT(usize) bufwriter_write_u8(bufwriter_t *self, u8_t value)
{
    return (bufwriter_write(self, &value, sizeof(u8_t)));
}

OPT(usize) bufwriter_write_u16(bufwriter_t *self, u16_t value)
{
    return (bufwriter_write(self, &value, sizeof(u16_t)));
}

OPT(usize) bufwriter_write_u32(bufwriter_t *self, u32_t value)
{
    return (bufwriter_write(self, &value, sizeof(u32_t)));
}

OPT(usize) bufwriter_write_u64(bufwriter_t *self, u64_t value)
{
    return (bufwriter_write(self, &value, sizeof(u64_t)));
}

OPT(usize) bufwriter_write_usize(bufwriter_t *self, usize_t value)
{
    return (bufwriter_write(self, &value, sizeof(usize_t)));
}
