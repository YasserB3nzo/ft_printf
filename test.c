#include <unistd.h>
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_valid_base(char *base)
{
	int i, j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		base_len;

	if (!is_valid_base(base))
		return;
	nb = nbr;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base);
	ft_putchar(base[nb % base_len]);
}
int main()
{
	char str[] = "hh" ;
	
    //ft_putnbr_base(2004,"abcdefhngjnbjkdfgnbl");
   // write(1,"done",4);
	printf("%p",*&str);
    return (0);
}