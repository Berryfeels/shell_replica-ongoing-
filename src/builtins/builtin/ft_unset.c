#include "../../../include/minishell.h"

int    handle_unset(char **av)
{
    if (!av[1])
    {
        fprintf (stderr, "unset: missing argument\n");
        return (EXIT_FAILURE);
    }
    if (unsetenv(av[1]) != 0)
    {
        perror ("unset");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}