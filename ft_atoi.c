#include "libft.h"

int		ft_atoi(const char *str)
{
	int		r;
	int		sign;

	r = 0;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		sign = ((*(str++) == '+') ? 1 : -1);
	while (ft_isdigit(*str))
	{
		r = (sign == 1) ? (r * 10 + (*str - '0')) : (r * 10 - (*str - '0'));
		str++;
	}
	return (r);
}
