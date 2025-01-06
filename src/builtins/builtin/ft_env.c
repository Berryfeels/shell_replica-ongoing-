#include "../../../include/minishell.h"

int handle_env(char **av)
{
    (void)av;
    int i;

    i = 0;
    while (g_msh.env[i])
    {
        printf("%s\n", g_msh.env[i++]);
    }
    return (0);
}
