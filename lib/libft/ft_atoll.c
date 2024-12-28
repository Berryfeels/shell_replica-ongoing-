#include "libft.h"

int	ft_isllong(char *str)
{
	if (str[0] == '-' && ft_strlen(str) >= 20
		&& ft_strcmp(&str[1], "9223372036854775808") > 0)
		return (1);
	else if (ft_strlen(str) >= 19
		&& ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	return (0);
}