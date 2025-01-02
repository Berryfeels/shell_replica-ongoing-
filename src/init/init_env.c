#include "../../include/minishell.h"

void    check_shlvl(void)
{
    char    *var;
    char    *value;
    int     shlvl;
    char    *new_var;

    var = ms_get_env (g_msh.env, "SHLVL");
    if (!var)
    {
        g_msh.env = ms_matrix_add_line(g_msh.env, "SHLVL=1");
        return ;
    }
    value = ms_get_varenv (g_msh.env, "SHLVL");
    if (!value || ft_isdigit(value[0]) == 0)
    {
        ft_printf("Warning: invalid SHLVL value. Resetting to 1\n");
        free (value);
        g_msh.env = ms_matrix_add_line (g_msh.env, "SHLVL=1");
        return ;
    }
    shlvl = ft_atoi (value);
    free (value);
    if (shlvl < 0)
        shlvl = 1;
    else
        shlvl++;
    value = ft_itoa (shlvl);
    new_var = ft_strjoin ("SHLVL=", value);
    free (value);
    ms_set_env (g_msh.env, new_var);
    free (new_var);
}

void    init_env(char **env)
{
    int i;

    i = 0;
    if (!env)
    {
        fprintf(stderr, "Error: env is NULL\n");
        exit(EXIT_FAILURE);
    }
    while (env[i])
        i++;
    g_msh.env = malloc(sizeof(char *) * (i + 1));
    if (!g_msh.env)
    {
        perror ("malloc failed\n");
        exit (EXIT_FAILURE);
    }
    i = 0;
    while (env[i])
    {
        g_msh.env[i] = ft_strdup (env[i]);
        i++;
    }
    g_msh.env[i] = NULL;
    check_shlvl();
}