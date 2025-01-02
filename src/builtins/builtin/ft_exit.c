#include "../../../include/minishell.h"

int check_exit(char *av)
{
    long long   exit_code;
    int         i;

    i = 0;
    if (!av)
        return (0);
    while (av[i] == ' ')
        i++;
    if (av[i] == '+' || av[i] == '-')
        i++;
    if (!ft_isdigit(av[i]))
    {
        ft_printf ("exit: %s isn't numeric argument\n", av);
        g_msh.ret_exit = 255;
        return (1);
    }
    exit_code = ft_atoll(av);
    if (ft_isllong(av) != 0 || exit_code < LLONG_MIN || exit_code > LLONG_MAX)
    {
        ft_printf ("exit: %s isn't numeric", av);
        g_msh.ret_exit = 255;
        return (1);
    }
    g_msh.ret_exit = exit_code % 256;
	if (g_msh.ret_exit < 0)
		g_msh.ret_exit += 256;
	return (0);
}

int    handle_exit(char **av)
{
    int i;

    ft_printf ("ciao\n");
    if (!av[1])
        exit (g_msh.ret_exit);
    i = check_exit(av[1]);
	if (av[2] && i == 0)
	{
        ft_printf ("exit: too many arguments\n");
        g_msh.ret_exit = 1;
        return (1);
    }
    exit(g_msh.ret_exit);
    return (0);
}