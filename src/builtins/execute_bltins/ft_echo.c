#include "../../include/minishel.h"

int    handle_echo(char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        printf ("%s", av[1]);
        i++;
    }
    printf ("\n");
    return (EXIT_SUCCESS);
}
