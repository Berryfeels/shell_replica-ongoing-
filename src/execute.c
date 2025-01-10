// #include "../include/minishell.h"
// #include <unistd.h>

// char *read_input(void)
// {
//     char cwd[1024];
//     if (getcwd(cwd, sizeof(cwd)) != NULL)
//     {
//         char prompt[1064];
//         int i = 0;
//         while (cwd[i] != '\0')
//         {
//             prompt[i] = cwd[i];
//             i++;
//         }
//         prompt[i++] = ' ';
//         prompt[i++] = 'M';
//         prompt[i++] = 'e';
//         prompt[i++] = 's';
//         prompt[i++] = 't';
//         prompt[i++] = 'e';
//         prompt[i++] = 'p';
//         prompt[i++] = 'u';
//         prompt[i++] = 'm';
//         prompt[i++] = '>';
//         prompt[i++] = ' ';
//         prompt[i] = '\0';

//         char *line = readline(prompt);
//         if (line && *line)
//             add_history(line);
//         return line;
//     }
//     else
//     {
//         perror("getcwd() error");
//         return NULL;
//     }
// }

// void    shell_loop(bld_in *builtins)
// {
//     char    *line;
//     t_token *tokens;
    
//     while (1)
//     {
//         ft_dprintf("shell_loop\n");
//         line = read_input();
//         if (!line || strcmp(line, "exit") == 0)
//         {
//             free(line);
//             break;
//         }
//         tokens = tokenize_input(line);
//         free(line);
//         if (!tokens)
//             continue ;
//         // Print the tokens
//         for (int i = 0; tokens[i].value != NULL; i++)
//         {
//             printf("Token %d: %s (Type: %d)\n", i, tokens[i].value, tokens[i].type);
//         }

//        // execute(builtins, tokens);
//         free_tokens (tokens);
//     }
// //    cleanup(builtins);
// }