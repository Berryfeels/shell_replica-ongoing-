#include "../include/minishell.h"
#include <unistd.h>

char *read_input(void)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        char prompt[1064];
        int i = 0;
        while (cwd[i] != '\0')
        {
            prompt[i] = cwd[i];
            i++;
        }
        prompt[i++] = ' ';
        prompt[i++] = 'M';
        prompt[i++] = 'e';
        prompt[i++] = 's';
        prompt[i++] = 't';
        prompt[i++] = 'e';
        prompt[i++] = 'p';
        prompt[i++] = 'u';
        prompt[i++] = 'm';
        prompt[i++] = '>';
        prompt[i++] = ' ';
        prompt[i] = '\0';

        char *line = readline(prompt);
        if (line && *line)
            add_history(line);
        return line;
    }
    else
    {
        perror("getcwd() error");
        return NULL;
    }
}

char **parse_input(char *line)
{
    char **tokens = tokenize_input(line);
    free(line);
    if (!tokens || !tokens[0])
    {
        free_tokens(tokens);
        return NULL;
    }
    return tokens;
}

void execute(bld_in *builtins, char **tokens)
{
    bld_in *bltin = find_builtin(builtins, tokens[0]);
    if (bltin)
        g_msh.ret_exit = bltin->func(tokens);
    else
        g_msh.ret_exit = exec_external_cmd(tokens);
}

void    shell_loop(bld_in *builtins)
{
    char    *line;
    char    **tokens;
    int     status;

    status = 1;
    while (status)
    {
        ft_dprintf("shell_loop\n");
        line = read_input();
        if (!line)
            break ;
        tokens = parse_input(line);
        if (!tokens)
            continue ;
        execute(builtins, tokens);
        free_tokens (tokens);
    }
//    cleanup(builtins);
}