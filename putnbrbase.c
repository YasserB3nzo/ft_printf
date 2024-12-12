/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:24:20 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/12 23:26:30 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	putnbrbase(long number, const char *base, int base_length)
{
	int		count;
	int		i;
	char	result[64];

	count = 0;
	i = 0;
	if (!checkputnbr(number, base))
		return (1);
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
	return (count);
}
