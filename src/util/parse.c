#include "../include/minishell.h"

char    *read_input(void)
{
    char    *line;

    line = readline ("Mestepum> ");
    if (line && *line)
    {
        add_history (line);
        return (line);
    }
    free (line);
    return (NULL);
}

char    **tokenize_input(char *line)
{
    char    **tokens;
    int     i;
    char    *token;

    tokens = malloc(sizeof(char *)  * MAX_TOKENS);
    if (!tokens)
    {
        perror("malloc failed");
        return NULL;
    }
    i = 0;
    token = ft_strtok (line, " ");
    while (token)
    {
        tokens[i] = ft_strdup (token);
        if (!tokens[i])
        {
            perror ("malloc failed\n");
            while (i > 0)
                free (tokens[--i]);
            free (tokens);
            return (NULL);
        }
        i++;
        if (i >= MAX_TOKENS)
        {
            fprintf (stderr, "too many tokens\n");
            break ;
        }
        token = ft_strtok (NULL, " ");
    }
    tokens[i] = NULL;
    return (tokens);
}