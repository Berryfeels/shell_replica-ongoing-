// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   expand.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/26 14:54:48 by codespace         #+#    #+#             */
// /*   Updated: 2024/12/26 16:23:32 by codespace        ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../include/minishell.h"

// char *expand(char *var)
// { 
//     int i;
//     char *var_content;

//     i = 0;
//     var_content = NULL;
//     while (g_msh.env[i])
//     {
//         if (strncmp(g_msh.env[i], var, strlen(var)) == 0 && g_msh.env[i][strlen(var)] == '=')
//         {
//             var_content = g_msh.env[i] + strlen(var) + 1;
//             break;
//         }
//         i++;
//     }
//     if (!g_msh.env[i]) 
//     {
//         perror("variable not found among environment variables");
//         return (NULL);
//     }
//     return ft_strdup(var_content);
// }

// int main(int argc, char **argv, char **env)
// {
//     char *var = "SHELL";
//     char *var_content;
    
//     var_content = expand(var, env);
//      if (var_content)
//     {
//         printf("%s\n", var_content);
//         free(var_content);
//     }
//     return (0);
// }