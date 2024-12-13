#include "../../../include/minishell.h"
/*
int    handle_pwd(void)
{
    char    cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s\n", cwd);
        return (EXIT_SUCCESS);
    }
    else
    {
        perror ("pwd");
        return (EXIT_FAILURE);
    }
}
*/
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

void    shell_loop(bld_in *builtin)
{
    char    *line;
    char    **tokens;

    while (1)
    {
        line = read_input();
        if (!line)
            break ;
        tokens = tokenize_input(line);
        free (line);
        if (!tokens || !tokens[0])
        {
            free_tokens (tokens);
            continue ;
        }
        builtin = find_builtin(builtin, tokens[0]);
        if (builtin)
            builtin->func(tokens);
        else
        {
            if (fork() == 0)
            {
                perror ("minishell");
                exit (EXIT_FAILURE);
            }
            else
                wait (NULL);
        }
        free_tokens (tokens);
    }
}
