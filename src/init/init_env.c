#include "../../include/minishell.h"

void    check_shlvl(void)
{
    char    *var;
    char    *var1;
    int     n;
    char    **av;

    var = ms_get_env (g_msh.env, "SHLVL");
    if (var == NULL)
    {
        g_msh.env = ms_matrix_add_line(g_msh.env, "SHLVL=1");
        return ;
    }
    av = ft_split(var, '=');
    n = ft_atoi (av[1]);
    n++;
    var = ft_itoa (n);
    var1 = ft_strjoin ("SHLVL=", var);
    ms_set_env (g_msh.env, var1);
    free (var);
    free (var1);
    ft_free_tab (av);
    return ;
}

void    init_env(char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    g_msh.env = malloc(sizeof(char *) * (i + 1));
    i = -1;
    while (env[++i])
        g_msh.env[i] = ft_strdup (env[i]);
    g_msh.env[i] = NULL;
    check_shlvl();
    return ;
}