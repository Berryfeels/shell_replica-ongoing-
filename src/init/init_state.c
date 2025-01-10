#include "../../include/minishell.h"

void    init_state(t_tokenizer *state)
{
    state->buf_idx = 0;
    state->i = 0;
    state->cur_state = TEXT;
    memset (state->token_buffer, 0, sizeof(state->token_buffer));
}