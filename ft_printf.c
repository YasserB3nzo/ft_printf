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
    int count = 0;
    char result[64];
    int i = 0;

    if (number == 0)
    {
        write(1, &base[0], 1);
        return 1;
    }
    if (number < 0)
    {
        write(1, "-", 1);
        number = -number;
        count++;
    }
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
    int count = 0;

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
    else if (c == 'c')
    {
        char x = (char)va_arg(args, int);
        write(1, &x, 1);
        count = 1;
    }
    else if (c == '%')
    {
        write(1, "%", 1);
        count = 1;
    }
    else
        count = -1;
    return count;
}

int ft_printf(const char *datatype, ...)
{
    int count = 0;
    va_list args;
    const char *str = datatype;

    if (!datatype)
        return -1;
    va_start(args, datatype);
    while (*str)
    {
        if (*str == '%')
        {
            int ret = datatype_check(*(++str), args);
            if (ret < 0)
            {
                count = -1;
                break;
            }
            count += ret;
        }
        else
        {
            write(1, str, 1);
            count++;
        }
        str++;
    }
    va_end(args);
    return count;
}
