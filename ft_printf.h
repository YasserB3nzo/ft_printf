#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_putstr(const char *str);
int putnbrbase(long number, const char *base, int base_length);
int putpointer(unsigned long ptr_address);
int datatype_check(char c, va_list args);
int ft_printf(const char *datatype, ...);
int checkchar(char c,va_list args);
int checkputnbr(long number, const char *base);
int process_format(const char *str, va_list args);

#endif