#include "../include/minishell.h"

void    shell_loop(bld_in *builtins)
{
    char    *line;
    char    **tokens;
    bld_in  *bltin;
    int     status;

    status = 1;
    while (status)
    {
        ft_dprintf("shell_loop\n");
        int i = 0;
        while(g_msh.env[i])
        {
            ft_dprintf("envp[%d]: %s\n", i, g_msh.env[i]);
            i++;
        }
        line = readline("Mestepum> ");
        if (!line)
            break ;
        if (*line)
            add_history(line);
        tokens = tokenize_input(line);
        free (line);
        if (!tokens || !tokens[0])
        {
            free_tokens (tokens);
            continue ;
        }
        //expansion
        //redirection
        bltin = find_builtin(builtins, tokens[0]);
        if (bltin)
            g_msh.ret_exit = bltin->func(tokens);
        else
        {
            g_msh.ret_exit = exec_external_cmd(tokens);
        }
        free_tokens (tokens);
    }
//    cleanup(builtins);
}
