#include "../include/minishell.h"

void    init_state(t_tokenizer *state)
{
    state->buf_idx = 0;
    state->i = 0;
    state->in_singles = 0;
    state->in_doubles = 0;
    memset (state->token_buffer, 0, sizeof(state->token_buffer));
}