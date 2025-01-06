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
        g_msh.env = ms_matrix_add_line(env, value);
    else
    {
        free (env[i]);
        env[i] = ft_strdup (value);
    }
    ft_free_tab (av);
}

static int find_env_index(char **env, char *var)
{
    int     i;
    char    **split;

    i = 0;
    while (env[i])
    {
        split = ft_split(env[i], '=');
        if (ft_strcmp(split[0], var) == 0)
        {
            ft_free_tab(split);
            return i;
        }
        ft_free_tab(split);
        i++;
    }
    return -1;
}

char **ms_remove_line(char **matrix, int index)
{
    int     i;
    int     j;
    char    **new_matrix;

    i = 0;
    while (matrix[i])
        i++;
    new_matrix = malloc(sizeof(char *) * i);
    if (!new_matrix)
        return NULL;
    i = 0;
    j = 0;
    while (matrix[i])
    {
        if (i != index)
        {
            new_matrix[j] = ft_strdup(matrix[i]);
            j++;
        }
        i++;
    }
    new_matrix[j] = NULL;
    ft_free_tab(matrix);
    return new_matrix;
}

int ms_unset_env(char **env, char *var)
{
    int index;

    index = find_env_index(env, var);
    if (index != -1)
    {
        g_msh.env = ms_remove_line(env, index);
        return (0);
    }
    return(1);
}