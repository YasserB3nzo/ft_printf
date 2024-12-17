#include "ft_printf.h"
 int main()

{
    int i =ft_printf(" Yasser Benzidiya %d\n",-123);
    int j = printf(" yasser benzidiya %d\n",-123);
    ft_printf("f : %d \t p : %d",i , j);
}