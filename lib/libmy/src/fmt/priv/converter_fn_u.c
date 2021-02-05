/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion functions for %b, %o, %u, %x and %X
*/

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "my/my.h"
#include "my/cstr.h"
#include "my/fmt/priv/converter.h"

static usize_t put_digits(bufwriter_t *bw, uintmax_t nb, char const *base)
{
    const uintmax_t base_len = (uintmax_t) my_cstrlen(base);
    int bytes_written = 0;
    uintmax_t d = nb % base_len;

    if (nb / base_len)
        bytes_written += put_digits(bw, nb / base_len, base);
    if (bw != NULL)
        bufwriter_putchar(bw, base[d]);
    return (bytes_written + 1);
}

static uintmax_t get_arg(my_fmt__converter_t *cv, va_list ap)
{
    switch (cv->len_mod) {
    case MY_FMT__LEN_MOD_HH:
        return ((uintmax_t) ((u8_t) va_arg(ap, u32_t)));
    case MY_FMT__LEN_MOD_H:
        return ((uintmax_t) ((u16_t) va_arg(ap, u32_t)));
    case MY_FMT__LEN_MOD_L:
        return ((uintmax_t) va_arg(ap, u64_t));
    case MY_FMT__LEN_MOD_Z:
        return ((uintmax_t) va_arg(ap, usize_t));
    case MY_FMT__LEN_MOD_J:
        return ((uintmax_t) va_arg(ap, uintmax_t));
    case MY_FMT__LEN_MOD_T:
        return ((uintmax_t) va_arg(ap, isize_t));
    case MY_FMT__LEN_MOD_PTR:
        return ((uintmax_t) va_arg(ap, usize_t));
    default:
        return ((uintmax_t) va_arg(ap, u32_t));
    }
}

static char const *get_base_from_spec(char conversion_specifier)
{
    switch (conversion_specifier) {
    case 'b':
        return (BINARY_BASE);
    case 'o':
        return (OCTAL_BASE);
    case 'u':
        return (DECIMAL_BASE);
    case 'x':
        return (LOWER_HEX_BASE);
    case 'X':
        return (UPPER_HEX_BASE);
    }
    return (NULL);
}

static int put_prefix(bufwriter_t *bw, my_fmt__converter_t *cv, uintmax_t nb,
    int next_is_zero)
{
    char cv_spec = cv->conversion_specifier;
    char const *prefix = NULL;
    int prefixlen = 0;

    if (nb == 0 || !cv->flags->alternate || (cv_spec == 'o' && next_is_zero))
        return (0);
    if (cv_spec == 'o')
        prefix = "0";
    else if (cv_spec == 'x' || cv_spec == 'X')
        prefix = cv_spec == 'x' ? "0x" : "0X";
    prefixlen = prefix == NULL ? 0 : my_cstrlen(prefix);
    if (bw)
        return (bufwriter_write(bw, prefix, prefixlen).v);
    return (prefixlen);
}

usize_t my_fmt__converter_fn_u(my_fmt__converter_t *cv, bufwriter_t *bw,
    va_list ap)
{
    int bytes_written = 0;
    int pad = 0;
    char padchar = cv->precision < 0 && cv->flags->zero ? '0' : ' ';
    char const *base = get_base_from_spec(cv->conversion_specifier);
    uintmax_t nb = get_arg(cv, ap);
    int digits = put_digits(NULL, nb, base);
    int extra_precision = cv->precision - digits;

    if (cv->precision == 0 && nb == 0)
        return (0);
    pad = cv->field_width - put_prefix(NULL, cv, nb, extra_precision > 0);
    pad -= MY_MAX(digits, cv->precision);
    if (!cv->flags->leftpad)
        bytes_written += put_nchr(bw, padchar, pad);
    bytes_written += put_prefix(bw, cv, nb, extra_precision > 0);
    bytes_written += put_nchr(bw, '0', extra_precision);
    bytes_written += put_digits(bw, nb, base);
    if (cv->flags->leftpad)
        bytes_written += put_nchr(bw, ' ', pad);
    return (bytes_written);
}
