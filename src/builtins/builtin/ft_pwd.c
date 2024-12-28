#include "../../../include/minishell.h"

int    handle_pwd(char **av)
{
    (void)av;
    char    cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
        return (0);
    }
    else
    {
        perror ("pwd");
        return (1);
    }
}