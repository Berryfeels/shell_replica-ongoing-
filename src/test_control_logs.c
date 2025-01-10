
#include "../include/minishell.h"

void control_log (t_token *tokens)
{
    int i = 0;
    // Print the tokens type
    // while (tokens.type != NULL)
    // {
    //     ft_dprintf("Token types: (Type: %d)\n", tokens[i].type);
    //     i++;
    // }
    // Print the tokens
    ft_dprintf ("________NEW LOG_______\n");
    i = 0;
    while (tokens[i].value != NULL)
    {
        ft_dprintf("Token %d: %s (Type: %d)\n", i, tokens[i].value, tokens[i].type);
        i++;
    }
}

void initialize_error_log(void)
{
    int fd = open("ErrorScan.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd == -1)
    {
        perror("Error opening ErrorScan.txt");
        exit(EXIT_FAILURE);
    }
    close(fd);
}