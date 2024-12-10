#include "ft_printf.h"

int checkchar(char c,va_list args)
{
    char x ;
    if (c == 'c')
    {
        x = (char)va_arg(args, int);
        write(1, &x, 1);
        return (1);
    }
    else if (c == '%')
    {
        write(1, "%", 1);
        return (1);
    }
    else
        return (-1);
}

int checkputnbr(long number, const char *base)
{
   if (number == 0)
    {
        write(1, &base[0], 1);
        return 0;
    }
    if (number < 0)
    {
        write(1, "-", 1);
        number = -number;
    }
    return 1;
}

int process_format(const char *str, va_list args)
{
    int count;
    int ret;

    count = 0;
    while (*str)
    {
        if (*str == '%')
        {
            ret = datatype_check(*(++str), args);
            if (ret < 0)
            {
                return -1; // Return early on error
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
    return count;
}
