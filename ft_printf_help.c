/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:06:55 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/12 22:23:15 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	checkchar(char c, va_list args)
{
	char	x;

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

int	checkputnbr(long *number)
{
	if (*number == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	if (*number < 0)
	{
		write(1, "-", 1);
		*number = - *number;
		return (1);
	}
		return (2);
}

int	process_format(const char *str, va_list args)
{
	int	count;
	int	ret;
	int	i;

	count = 0;
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret = datatype_check(str[i], args);
			if (ret < 0)
				return (-1);
			count += ret;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
