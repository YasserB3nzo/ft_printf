#include "ft_printf.h"

int ft_putstr(const char *str)
{
    int count;

    count = 0;
    if (!str)
    {
        write(1, "(null)", 6);
        return 6;
    }
    while (str[count])
    {
        write(1, &str[count], 1);
        count++;
    }
    return count;
}

int putnbrbase(long number, const char *base, int base_length)
{
    int count;
    char result[64];
    int i;

    count = 0;
    i = 0;
    if(!checkputnbr(number,base))
        return 1;
    count++;
    while (number)
    {
        result[i++] = base[number % base_length];
        number /= base_length;
    }
    while (--i >= 0)
    {
        write(1, &result[i], 1);
        count++;
    }
    return count;
}

int putpointer(unsigned long ptr_address)
{
    int count;

    count = 0;
    if (!ptr_address)
    {
        write(1, "(null)", 6);
        return 6;
    }
    write(1, "0x", 2);
    count += 2;
    count += putnbrbase(ptr_address, "0123456789abcdef", 16);
    return count;
}

int datatype_check(char c, va_list args)
{
    int count;

    count = 0;
    if (c == 'd' || c == 'i')
        count = putnbrbase((long)va_arg(args, int), "0123456789", 10);
    else if (c == 'u')
        count = putnbrbase((long)va_arg(args, unsigned int), "0123456789", 10);
    else if (c == 's')
        count = ft_putstr(va_arg(args, char *));
    else if (c == 'x')
        count = putnbrbase((unsigned int)va_arg(args, int), "0123456789abcdef", 16);
    else if (c == 'X')
        count = putnbrbase((unsigned int)va_arg(args, int), "0123456789ABCDEF", 16);
    else if (c == 'p')
        count = putpointer(va_arg(args, unsigned long));
    count = checkchar(c,args);
    return count;
}

int ft_printf(const char *datatype, ...)
{
    int     count;
    va_list args;

    if (!datatype)
        return -1;

    va_start(args, datatype);
    count = process_format(datatype, args);
    va_end(args);

    return count;
}

