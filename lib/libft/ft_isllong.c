#include "libft.h"

long long	ft_atoll(const char *nptr)
{
	long long	num;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		nptr++;
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		nptr++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + nptr[i] - '0';
		nptr++;
	}
	return (num * sign);
}