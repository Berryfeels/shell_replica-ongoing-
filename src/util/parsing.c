#include "../../include/minishell.h"

void handle_quotes(char c, t_tokenizer *state)
{
    if (state->cur_state == TEXT)
    {
        if (c == '\'')
            state->cur_state = S_QUOTE; // Enter single-quote mode
        else if (c == '\"')
            state->cur_state = D_QUOTE; // Enter double-quote mode
        else
            state->token_buffer[state->buf_idx++] = c; // Append non-quote chars
    }
    else if (state->cur_state == S_QUOTE)
    {
        if (c == '\'')
            state->cur_state = TEXT; // Exit single-quote mode
        else
            state->token_buffer[state->buf_idx++] = c; // Append inside single quotes
    }
    else if (state->cur_state == D_QUOTE)
    {
        if (c == '\"')
            state->cur_state = TEXT; // Exit double-quote mode
        else
            state->token_buffer[state->buf_idx++] = c; // Append inside double quotes
    }
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
    else if (c == '$' || (c == '$' && next == '?'))
    {
        token_buffer[0] = c;
        if (next == '?')
        {
            token_buffer[1] = next;
            token_buffer[2] = '\0';
        }
        else
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
    t_tokenizer     state;
    char            c;
    int             token_idx;

    token_idx = 0;
    if (ft_strlen(line) >= MAX_BUFFER)
    {
        fprintf(stderr, "Error: Input too long\n");
        return NULL;
    }
    tokens = ft_calloc(MAX_TOKENS, sizeof(char *));
    if (!tokens)
    {
        perror("calloc failed\n");
        return NULL;
    }
    init_state (&state);
    while (line[state.i] != '\0')
    {
        c = line[state.i];
        if (isspace(c) && state.cur_state == TEXT)
        {
            if (state.buf_idx > 0) // Finish current token
            {
                state.token_buffer[state.buf_idx] = '\0'; // Null-terminate
                tokens[token_idx++] = strdup(state.token_buffer); // Save token
                state.buf_idx = 0; // Reset buffer
            }
        }
        else
        {
            handle_quotes(c, &state);
        }
        state.i++;
    }
    if (state.buf_idx > 0)
    {
        state.token_buffer[state.buf_idx] = '\0';
        tokens[token_idx++] = strdup(state.token_buffer);
    }
    tokens[state.i] = NULL;

    int j = 0;
    while (tokens[j] != NULL)
    {
        printf("Token %d: %s\n", j, tokens[j]);
        j++;
    } 

    return (tokens);
}