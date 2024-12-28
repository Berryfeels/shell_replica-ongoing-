#include "../../../include/minishell.h"

int    handle_export(char **av)
{
    if (!av[1])
    {
        fprintf(stderr, "export: missing argument\n");
        return (EXIT_FAILURE);
    }
    if (putenv(av[1]) != 0)
    {
        perror ("exposrt");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}