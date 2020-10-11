#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n < 0)
	{
		if (n < -9)
			ft_putnbr(-(n / 10));
		ft_putchar('0' + ((10 - (n % 10)) % 10));
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar('0' + (n % 10));
	}
}
