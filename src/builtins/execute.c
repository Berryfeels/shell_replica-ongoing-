#include "../../include/minishell.h"

void    shell_loop(bld_in *builtins)
{
    char    *line;
    char    **tokens;
    bld_in  *bltin;
    int     status;

    status = 1;
    while (status)
    {
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
        bltin = find_builtin(builtins, tokens[0]);
        if (bltin)
            status = bltin->func(tokens);
        else
        {
            status = exec_external_cmd(tokens);
        }
        free_tokens (tokens);
    }
//    cleanup(builtins);
}
