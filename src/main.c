/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:01:45 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/04 15:33:26 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(void)
{
    char *line;
    t_token *tokens;

	signal_handler();
    while (1)
    {
        // Prompt for user input
        line = read_input();
        if (!line || strcmp(line, "exit") == 0 || line == NULL)
        {
            //check test for ctrl d
            if (line == NULL)
                printf("exit ctrl d\n");
            free(line);
            break;
        }
        // Tokenize the input
        tokens = tokenize_input(line);
        free(line);

        // Print the tokens
        for (int i = 0; tokens[i].value != NULL; i++)
        {
            printf("Token %d: %s (Type: %d)\n", i, tokens[i].value, tokens[i].type);
        }

        free_tokens(tokens);
    }

    return 0;
}