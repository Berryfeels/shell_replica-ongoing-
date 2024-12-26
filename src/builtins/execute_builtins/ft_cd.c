#include "../../../include/minishell.h"

void    update_env(char *av, char *c)
{
    char    *string;

    string = ft_strjoin(av, c);
    ms_set_env (g_msh.env, string);
    free (string);
}

int    handle_cd(char **av)
{
    char    cwd[1024];
    char    *home;
    char    *oldpwd;

    home = getenv("HOME");
    if (!av[1])
    {
        if (!home)
        {
            fprintf (stderr, "cd: HOME not set\n");
            return (EXIT_FAILURE);
        }
        if (chdir (home) == 0)
            update_env ("OLDPWD", cwd);
    }
    else if (strcmp(av[1], "-") == 0)
    {
        oldpwd = getenv("OLDPWD");
        if (!oldpwd)
        {
            fprintf (stderr, "cd: OLDPWD not set\n");
            return (EXIT_FAILURE);
        }
    }
    else
    {
        if (chdir(av[1]) == 0)
            update_env("OLDPWD", cwd);
        else
            perror ("cd");
    }
    if (getcwd (cwd, sizeof(cwd)))
        update_env ("PWD", cwd);
    return (EXIT_SUCCESS);
}