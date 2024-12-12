/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:24:08 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/12 23:28:42 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
	return (count);
}

int	putpointer(unsigned long ptr_address)
{
	int	count;

	count = 0;
	if (!ptr_address)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, "0x", 2);
	count += 2;
	count += putnbrbase(ptr_address, "0123456789abcdef", 16);
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

// strdarg declar 4 macros
// macro is a code segment that is replaced during compilation
//va_list is a array of type struct that stores x amount of arguments
// va_start macro that initialise va list /by pointing to the first argumment 
// va_arg macro that returns the next argument in the list 
// va_arg takes 2 arguments the va_list and the type of the next argument
// va_end macro that cleans up the va_list
// va list inplemented as a struct / alias that represents the tools required to track variable arguments 
// tools are the information needed to track the args
// current position to track the memory adress/register offset of the next argument to be accessed
