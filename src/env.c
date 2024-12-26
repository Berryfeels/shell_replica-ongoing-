#include "../include/minishell.h"

char    *ms_get_env(char **env, char *av)
{
    int     i;
    char    **split;

    i = 0;
    while (env[i])
    {
        split = ft_split (env[i], '=');
        if (ft_strcmp(split[0], av) == 0)
        {
            ft_free_tab (split);
            break ;
        }
        else
            i++;
        ft_free_tab (split);
    }
    if (env[i] == NULL)
        return (NULL);
    return (env[i]);
}

char    *ms_get_varenv(char **env, char *av)
{
    int     i;
    char    **split;
    char    *var_env;

    i = 0;
    var_env = NULL;
    while (env[i] && !var_env)
    {
        split = ft_split (env[i], '=');
        if (ft_strcmp(split[0], av) == 0)
            var_env = ft_strdup(split[1]);
        else
            i++;
        ft_free_tab (split);
    }
    if (env[i] == NULL)
        return (NULL);
    return (var_env);
}

int env_compare(char **env, char **av, int i)
{
    char    **split;

    while (env[i])
    {
        split = ft_split (env[i], '=');
        if (ft_strcmp(split[0], av[0]) == 0)
        {
            ft_free_tab(split);
            break ;
        }
        i++;
        ft_free_tab (split);
    }
    return (i);
}

void    ms_set_env(char **env, char *value)
{
    int     i;
    char    **av;

    i = 0;
    av = ft_split (value, '=');
    i = env_compare(env, av, i);
    if (env[i] == NULL)
    {
        g_msh.env = ms_matrix_add_line(env, value);
        ft_free_tab(av);
        return ;
    }
    free (env[i]);
    value = ft_strdup(value);
    env[i] = value;
    ft_free_tab (av);
}