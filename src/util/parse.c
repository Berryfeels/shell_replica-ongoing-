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

int handle_special_chars(char c, char next, t_token *tokens, t_tokenizer *state)
{
    if ((c == '<' && next == '<') || (c == '>' && next == '>'))
    {
        tokens[state->i].value = strndup(&c, 2);
        if (c == '<')
            tokens[state->i].type = HERE_DOC_L;
        else
            tokens[state->i].type = APPEND;
        state->i++;
        return (1);
    }
    else if (c == '|')
    {
        tokens[state->i].value = ft_strdup("|");
        tokens[state->i].type = PIPE;
        state->i++;
    }
    else if (c == '<')
    {
        tokens[state->i].value = ft_strdup("<");
        tokens[state->i].type = REDIR_L;
        state->i++;
    }
    else if (c == '>')
    {
        tokens[state->i].value = ft_strdup(">");
        tokens[state->i].type = REDIR_R;
        state->i++;
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

void    free_tokens(t_token *tokens)
{
    int i;

    i = 0;
    while (tokens[i].value != NULL)
    {
        free(tokens[i].value);
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

t_token    *tokenize_input(char *line)
{
    t_token         *tokens;
    t_tokenizer     state;
    char            c;

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
            handle_whitespace((char **)tokens, &state);
        else if (state.cur_state == TEXT && (c == '|' || c == '<' || c == '>'))
        {
            handle_whitespace((char **)tokens, &state);
            if (handle_special_chars(c, line[state.i + 1], tokens, &state))
                state.i++;
        }
        else
        {
            handle_quotes(c, &state);
        }
        state.i++;
    }
    handle_whitespace((char **)tokens, &state);
    tokens[state.i].value = NULL;
    tokens[state.i].type = VOID;
/*
    int j = 0;
    while (tokens[j] != NULL)
    {
        printf("Token %d: %s\n", j, tokens[j]);
        j++;
    } 
*/
    return (tokens);
}