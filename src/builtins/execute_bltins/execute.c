#include "minishell.h"

void    handle_echo(char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        printf ("%s", av[1]);
        i++;
    }
    printf ("\n");
}

void    handle_pwd(void)
{
    char    cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
    }
    else
        perror ("pwd");
}

void    handle_export(char **av)
{
    if (!av[1])
    {
        fprintf(stderr, "export: missing argument\n");
        return ;
    }
    if (putenv(av[1]) != 0)
        perror ("exposrt");
}

void    handle_unset(char **av)
{
    if (!av[1])
    {
        fprintf (stderr, "unset: missing argument\n");
        return ;
    }
    if (unsetenv(av[1]) != 0)
        perror ("unset");
}

void    handle_env(char **av)
{

}

void    shell_loop(void)
{
    char    *line;
    char    **tokens;

    while (1)
    {
        line = read_input();
        if (!line)
            break ;
        if (tokens)
        {
            execute_command (tokens);
            free_token (tokens);
        }
        free (line);
    }
}
