/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:49:08 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/04 15:25:14 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <unistd.h>
# include "../dprintf/ft_dprintf.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"


/******************************************************************************
*								MACROS										  *
******************************************************************************/

# define EXIT_ERROR 1
# define EXIT_SUCCESS 0
# define PATH_MAX 4096

/******************************************************************************
*								TOKENS										  *
******************************************************************************/
//give a definition to the different tokens
# define PIPE '|'

//DEFINE STRUCTURES

//pipes
typedef struct s_pipe
{
	struct s_pipe	*left;
	struct s_pipe	*right;
	int				typecode;
}		t_pipe;


//cmd
typedef struct s_cmd
{
	int		typecode;
}		t_cmd;

//execcmd
typedef struct s_exec
{
	int		typecode;
	char	**eargv;
	char	**argv;
}		t_exec;

//redirectcmd
typedef struct s_redir
{
	int		typecode;
	char	*file;
	char	*efile;
	int		mode;
	int		fd;
	char	*cmd;
}			t_redir;

//prompt call
// typedef struct s_call
// {
// 	char *promptstart;
// 	char *promptend;
// 	char 	;
// 	end cmd;
// 	typetoken;
	
// };

//token struct

typedef struct s_token
{
	char token;
} t_token;

//funtions
int	execute(char *cmd, char **envp);
void ft_pwd ();
void ft_cd(char *buff, char *prompt);

#endif