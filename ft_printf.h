#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_putstr(const char *str);
int putnbrbase(long number, const char *base, int base_length);
int putpointer(unsigned long ptr_address);
int datatype_check(char c, va_list args);
int ft_printf(const char *datatype, ...);

#endif