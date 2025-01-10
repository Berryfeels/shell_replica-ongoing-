#include "../../../include/minishell.h"

int    handle_export(char **av)
{
    if (!av[1])
    {
        fprintf(stderr, "export: missing argument\n");
        return (EXIT_FAILURE);
    }
    if (!ft_strchr(av[1], '='))
    {
        fprintf(stderr, "export: invalid format (expected key=value)\n");
        return (EXIT_FAILURE);
    }
    ms_set_env(g_msh.env, av[1]);
    return (EXIT_SUCCESS);
}