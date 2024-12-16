/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:24:08 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/16 21:55:54 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count + 1);
}

int	putpointer(void	*ptr_address)
{
	int	count;

	count = 0;
	if (!ptr_address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += 2;
	count += putnbrbase((unsigned long)ptr_address, "0123456789abcdef", 16);
	return (count);
}

int	ft_printf(const char *datatype, ...)
{
	int		count;
	va_list	args;

	if (!datatype)
		return (-1);
	va_start(args, datatype);
	count = process_format(datatype, args);
	va_end(args);
	return (count);
}

// variadic fct is fct  can take any amout of arguments 
// theres 2 types of register gp , fp .
// gp_ofsset can store int , pointers and flags 
// fp store flout and doubles
// theres 16 gp purpose registers and only the first 6 are used for arg
// same thing for fp purpose but the 8 first registers for args
// gp registers hold 8 bytes and fp hold 16 bytes : for evrey register  

// regitser storage place in cpu to hold data and instuctions 
// why , when we have ram : register aare workspace for cpu 
// register allow the cpu to manipulate and store data during in execution fatser then ram 
// for storing intermi values like res of calculation 

// strdarg declar 4 macros
// macro is a code segment that is replaced during compilation
// va_list data type
// va_list allow the fct to acces the additional args 
// va_list defined as a struct that represents the elements needed 
// to keep track of the arguments
// how ? by traking where the args are located in memory

// gp ofsset saved the loacation of the next arguments 
// and it acts as a index into the reg save area to calculate 
// where the next argumments is stored , its incrementd by the size of args 
// fp ofsset also do the same as gp
// overflowarea pointes where the arguments are stored in stack


										