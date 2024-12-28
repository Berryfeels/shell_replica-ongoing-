#include "../../../include/minishell.h"

int	ft_newline(char *av)
{
	int	i;

	i = 0;
	if (av && av[i++] == '-')
	{
		while (av[i])
		{
			if (av[i] != 'n')
				break ;
			if (av[i + 1] == '\0')
				return (true);
			i++;
		}
	}	
	return (false);
}

int    handle_echo(char **av)
{
    int i;
    int n;

    i = 0;
	n = false;
	while (ft_newline(av[i++]))
		n = true;
    while (av[i])
    {
        printf ("%s", av[i]);
		if (av[i + 1] != NULL)
			printf(" ");
        i++;
    }
	if (n == false)
    	printf ("\n");
    return (0);
}
