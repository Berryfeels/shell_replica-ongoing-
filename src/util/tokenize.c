#include "../../include/minishell.h"

static int add_token(t_token *tokens, int *token_count, char *value, t_type type)
{
	if (*token_count >= MAX_TOKENS - 1)
	{
		fprintf(stderr, "Error: Too many tokens\n");
		return (-1);
	}

	// Allocate and copy the token
	tokens[*token_count].value = strdup(value);
	tokens[*token_count].type = type;
	(*token_count)++;
	return (0);
}

/**
 * Finalize the current token in the buffer.
 */
static int finalize_token(t_tokenizer *state, t_token *tokens, int *token_count, t_type type)
{
	if (state->buf_idx > 0)
	{
		state->token_buffer[state->buf_idx] = '\0'; // Null-terminate the token
		if (add_token(tokens, token_count, state->token_buffer, type) == -1)
			return (-1);
		state->buf_idx = 0; // Reset the buffer index
	}
	return (0);
}

void handle_variable(char c, t_tokenizer *state)
{
    char temp[MAX_BUFFER];
    int var_len;
    char *var_value;

    var_len = 0;
    // If $ is inside single quotes, treat it as literal
    if (state->cur_state == S_QUOTE)
    {
        state->token_buffer[state->buf_idx++] = c;
        return;
    }

    // Collect the variable name
    state->i++; // Skip the $
    while (ft_isalnum(state->line[state->i]) || state->line[state->i] == '_')
    {
        temp[var_len++] = state->line[state->i];
        state->i++;
    }
    state->i--; // Rewind one step since we read past the variable

    temp[var_len] = '\0'; // Null-terminate variable name

    // Lookup the variable value from the environment
    var_value = getenv(temp); // Or use your custom environment function
    if (var_value)
    {
        while (*var_value)
            state->token_buffer[state->buf_idx++] = *var_value++;
    }
}

void handle_s_quote(char c, t_tokenizer *state)
{
    if (c == '\'') // Exit single-quote mode
    {
        state->cur_state = TEXT;
    }
    else
    {
        // Add character literally to the buffer
        state->token_buffer[state->buf_idx++] = c;
    }
}

void handle_d_quote(char c, const char *line, t_tokenizer *state)
{
    if (c == '\"') // Exit double-quote mode
    {
        state->cur_state = TEXT;
    }
    else if (c == '\\') // Handle escaped characters
    {
        state->i++; // Move to the next character
        if (line[state->i] != '\0') // Prevent buffer overrun
        {
            state->token_buffer[state->buf_idx++] = line[state->i];
        }
    }
    else if (c == '$') // Handle variable expansion
    {
        // Add custom logic for expanding variables (e.g., $HOME)
        handle_variable(c, state); // You can skip tokens here
    }
    else
    {
        // Add literal character to the buffer
        state->token_buffer[state->buf_idx++] = c;
    }
}

int handle_special_chars(char c, char next, t_tokenizer *state, t_token *tokens, int *token_count)
{
    char temp[3] = {c, '\0', '\0'};

    // Handle << and >>
    if ((c == '<' && next == '<') || (c == '>' && next == '>'))
    {
        temp[1] = next; // Add second character
        finalize_token(state, tokens, token_count, STRING); // Finish the current token
        add_token(tokens, token_count, temp, (c == '<') ? HERE_DOC_L : APPEND);
        state->i++; // Skip the next character
        return 1;
    }

    // Handle single special characters
    if (c == '<' || c == '>' || c == '|')
    {
        finalize_token(state, tokens, token_count, STRING); // Finish the current token
        add_token(tokens, token_count, temp, (c == '|') ? PIPE : (c == '<') ? REDIR_L : REDIR_R);
        return 1;
    }

    return 0; // Not a special character
}

void handle_whitespace(t_tokenizer *state, t_token *tokens, int *token_count)
{
    if (state->buf_idx > 0) // If there is something in the buffer
    {
        finalize_token(state, tokens, token_count, STRING);
    }
}

// char    *read_input(void)
// {
//     char    *line;

//     line = readline ("Mestepum> ");
//     if (line && *line)
//     {
//         add_history (line);
//         return (line);
//     }
//     free (line);
//     return (NULL);
// }

void process_token_types(t_token *tokens)
{
    t_token *prev_token = NULL;

    for (int i = 0; tokens[i].value != NULL; i++)
    {
        if (prev_token &&
            (prev_token->type == REDIR_L || prev_token->type == REDIR_R ||
             prev_token->type == APPEND || prev_token->type == HERE_DOC_L))
        {
            tokens[i].type = FILE_T; // Assign FILE type to the current token
        }

        prev_token = &tokens[i]; // Update the previous token
    }
}

t_token *tokenize_input(const char *line)
{
    t_tokenizer state;
    t_token *tokens;
    char c;
    int token_count = 0;

    tokens = calloc(MAX_TOKENS, sizeof(t_token));
    if (!tokens)
    {
        perror("calloc failed");
        return NULL;
    }

    memset(&state, 0, sizeof(t_tokenizer));
    state.cur_state = TEXT;

    while ((c = line[state.i]) != '\0')
    {
        if (state.cur_state == S_QUOTE)
        {
            handle_s_quote(c, &state);
        }
        else if (state.cur_state == D_QUOTE)
        {
            handle_d_quote(c, line, &state);
        }
        else if (isspace(c))
        {
            handle_whitespace(&state, tokens, &token_count);
        }
        else if (c == '\'')
        {
            state.cur_state = S_QUOTE;
        }
        else if (c == '\"')
        {
            state.cur_state = D_QUOTE;
        }
        else if (handle_special_chars(c, line[state.i + 1], &state, tokens, &token_count))
        {
            // Special character handled
        }
        else if (c == '\\' && line[state.i + 1] == '\n')
        {
            state.i++;
        }
        else
        {
            state.token_buffer[state.buf_idx++] = c;
        }
        
        state.i++;
    }

    finalize_token(&state, tokens, &token_count, STRING);

    tokens[token_count].value = NULL;
    tokens[token_count].type = VOID;

    process_token_types(tokens);

    return tokens;
}

void free_tokens(t_token *tokens)
{
    for (int i = 0; tokens[i].value != NULL; i++)
    {
        free(tokens[i].value);
    }
    free(tokens);
}