#include "../../include/minishell.h"

void    handle_quotes(char c, t_tokenizer *state)
{
    if (c == '\'' && !state->in_doubles)
        state->in_singles = !state->in_singles;
    else if (c == '"' && !state->in_singles)
        state->in_doubles = !state->in_doubles;
}

int handle_special_chars(char c, char next, char **tokens, t_tokenizer *state)
{
    char token_buffer[3] = {0};

    if ((c == '<' && next == '<') || (c == '>' && next == '>'))
    {
        token_buffer[0] = c;
        token_buffer[1] = next;
        token_buffer[2] = '\0';
        tokens[state->i++] = ft_strdup(token_buffer);
        return (1);
    }
    else if (c == '|' || c == '<' || c == '>')
    {
        token_buffer[0] = c;
        token_buffer[1] = '\0';
        tokens[state->i++] = ft_strdup(token_buffer);
    }
    return (0);
}

void    handle_whitespace(char **tokens, t_tokenizer *state)
{
    if (state->buf_idx > 0)
    {
        state->token_buffer[state->buf_idx] = '\0';
        tokens[state->i++] = strdup(state->token_buffer);
        state->buf_idx = 0;
    }
}

void    free_tokens(char **tokens)
{
    int i;

    i = 0;
    while (tokens[i] != NULL)
    {
        free(tokens[i]);
        i++;
    }
    free (tokens);
}

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
    char            **tokens;
    int             j;
    t_tokenizer    state;
    char            c;

    tokens = malloc(sizeof(char *)  * MAX_TOKENS);
    if (!tokens)
    {
        perror("malloc failed");
        return NULL;
    }
    j = 0;
    init_state (&state);
    while (line[j] != '\0')
    {
        c = line[j];
        handle_quotes(c, &state);
        if (!state.in_singles && !state.in_doubles && (c == '|' || c == '<' || c == '>'))
        {
            handle_whitespace (tokens, &state);
            if (handle_special_chars (c, line[j + 1], tokens, &state))
                j++;
        }
        else if (isspace (c) && !state.in_singles && !state.in_doubles)
            handle_whitespace (tokens, &state);
        else
            state.token_buffer[state.buf_idx++] = c;
    }
    handle_whitespace (tokens, &state);
    tokens[state.i] = NULL;
    return (tokens);
}

