#include "ft_printf.h"


 int ftputstr(const char *str)
  {
     int count;

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
    int baselent;
    int count ;

    count = 0;
    if(number == 0)
    {
        write(1,&base[0],1);
        return(1);
    }

    if(number < 0)
    {  
        write(1,"-",1);
        number = -number;
    }
    while(number)
    {
        write(1,&base[number%bl],1);
        number = number / bl;
        count ++;

    }
    return (count);
 }

//  int putpointer()
//  {

//  }

int datatypecheck(char datyp,va_list value)
{
    if(char == 'X')
        if
        return(putnbrbase(56656,nfvvr,16))
}
//  int ft_printf(char *dataype,...)
//  {
     
//  }
int main()
{
    putnbrbase(2004,"abcdefhngjnbjkdfgnbl",21);
    ft_printf("%X",65665646);
}
// variadic function are the fucntion that can take x arguments
//