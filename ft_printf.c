#include "ft_printf.h"

 int    ftputstr(const char *str)
  {
     int    count;

    if(!str)
        write(1,"(null)",6)
     count = 0;
     while(str[count])
     {
         write(1,&str[count],1);
        count++;
    }
     return (count);
 }

int putnbrbase(long number, char *base, int bl)
{
    int     count;
    char    result[64];
    int     i;
    
    i = 0;
    count = 0;
    if (number == 0)
    {
        write(1, &base[0], 1);
        return (1);
    }
    if (number < 0)
    {
        write(1, "-", 1);
        number = -number;
        count++;
    }
    while (number)
    {
        result[i++] = base[number % bl];
        number /= bl;
    }
    while (--i >= 0)
    {
        write(1, &result[i], 1);
        count++;
    }
    return (count);
}

//  int putpointer()
//  {
//  }

int dataypecheck(char c, va_list args)
{
    char    x;

    if (c == 'd' || c == 'i')
        return (putnbrbase((long)va_arg(args, int), "0123456789",10));
    if (c == 'u')
        return (putnbrbase((long)va_arg(args, unsigned int), "0123456789",10));
    if (c == 's')
        return (ft_putstr(va_arg(args, char *)));
    if (c == 'x')
        return (putnbrbase((unsigned int)va_arg(args, int), "0123456789abcdef",16));
    if (c == 'X')
        return (putnbrbase((unsigned int)va_arg(args, int), "0123456789ABCDEF",16));
    if (c == 'p')
        return (putpointer(va_arg(args, void *)));
    if (c == 'c')
    {
        x = va_arg(args, int); //it gets promotd to a int
        return (write(1, &x, 1));
    }
    if (c == '%')
        return (write(1, "%", 1));
    return (-1);
}
//  int ft_printf(const char *dataype,...)
//  {
//  }
int main()
{
    putnbrbase(2004,"abcdefhngjnbjkdfgnbl",21);
    ft_printf("%X","fgvfvns",'f',jhfbvjhsv,"bjhfdbvkd",'f',65665646);
}
// variadic function are the fucntion that can take x arguments
//