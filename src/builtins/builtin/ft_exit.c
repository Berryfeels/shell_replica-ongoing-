#include "../../../include/minishell.h"

int check_exit(char *av)
{
    long long   exit_code;
    int         i;

    i = 0;
    while (av[i] == ' ')
        i++;
    while (av[i] && (av[i] == '+' || av[i] == '-'))
        i++;
    if (ft_isdigit(av[i]) == 0 || ft_isllong(av) != 0)
    {
        ft_printf ("exit: %s isn't numeric argument\n", av);
        g_msh.ret_exit = 255;
        return (1);
    }
    exit_code = ft_atoll(av);
    g_msh.ret_exit = exit_code % 256;
	if (g_msh.ret_exit < 0 || g_msh.ret_exit > 255)
		g_msh.ret_exit = 255;
	return (0);
}

int    handle_exit(char **av)
{
    int i;

    i = 0;
    ft_printf ("exiting\n");
    if (av[0])
    {
        i = check_exit(av[0]);
		if (av[1] && i == 0)
		{
            ft_printf ("exit: too many arguments\n");
            g_msh.ret_exit = 1;
            return (1);
        }
    }
    exit(g_msh.ret_exit);
    return (0);
}