/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:02:51 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/20 20:26:39 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define BOUNDS " |><"
# define QUOTES "\'\""
# define EXP_LIMIT "!@#$%%^&*()-+=[]{}|\\:;'\"/<>,.`~ "

typedef enum e_token_type
{
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC,
	PIPE,
	ARG,
	INVALID,
}	t_token_type;

typedef struct s_tokens
{
	char			*value;
	t_token_type	type;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_msh
{
	char	**ms_env;
	char	**env_exp;
	char	*home_path;
	int		exit_code;
	int		prev_exit;
	int		node_n;
	int		redir_i;
	int		token_n;
	bool	start_node;
	bool	find_cmd;
	bool	pipestart;
	bool	found_echo;
}	t_msh;

typedef struct s_redir
{
	struct s_redir	*prev;
	int				type;
	int				redir_i;
	char			*target;
	int				fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	bool	option_n;
}	t_cmd;

typedef struct s_node_list
{
	int					fd_in;
	int					fd_out;
	t_msh				*msh;
	struct s_node_list	*prev;
	t_cmd				*cmd;
	t_redir				*redir;
	int					node_i;
	int					nodes_total;
	struct s_node_list	*next;
}	t_node_list;

/* _____________TOKENIZATION FUNCTIONS_____________ */

t_tokens	*return_tokens(char *input, t_msh *msh);
t_tokens	*tokenize(char *input, int *i, t_msh *msh, t_tokens *tokens);

/* allocate_tokens.c - creates a linked list of tokens and frees it */
void		append_token(t_tokens **head, t_tokens *new_token);
t_tokens	*create_token(const char *value, int type);
void		free_tokens(t_tokens *head);

/* tokenize_bounds.c : creates and appends tokens for | > < << and >> */
bool		valid_bound(char *input, int *i, t_tokens **tokens);
void		handle_left(char *input, int *i, t_tokens **tokens);
void		handle_right(char *input, int *i, t_tokens **tokens);

/* tokenize strings ( I define strings anything between
" ", ' ' and any char bnot divided by a space, pipe or redir) */
void		parse_string(char *input, int *i, t_msh *msh, char *buff);
void		quoted_buff(char *input, int *i, t_msh *msh, char *buff);
bool		empty_quoted(int *i, char *input);
void		unquoted_buff(char *input, int *i, t_msh *msh, char *buff);

/* handle_expansions.c */
char		*find_envar(char *var, char **env);
void		expand_to_buff(char *expansion, char *buff, int *len, t_msh *msh);
void		collect_expansion(char *input, int *i, char *buff, t_msh *msh);

/* stops buffer collection and if no error found appends node */
bool		stop_buffer(char *input, int *i, char *buff, t_msh *msh);

/* debugging */
void		print_tokens(t_tokens *tokens);

/* _____________NODE LIST CREATION FUNCTIONS_____________ */

/* MAIN PARSING FUNCTION - returns a node list (or null if error) to the main */
t_node_list	*return_nodes(t_tokens *token_list, t_msh *msh);

/* PARSES EACH TOKEN TO ASSIGN ITS FUNCTION INSIDE ITS NODE -
 *p contains data that allows us to do that */
bool		parse_token(t_msh *msh, t_tokens **token,
				t_node_list **head, t_node_list **new_node);

/* NODE FUNCTIONS (CREATE, APPEND, END) - alloc_nodes.c creates node list */
t_node_list	*init_new_node(int node_n, bool *start_node, t_msh *msh);
void		append_node(t_node_list **head, t_node_list *new_node);
void		end_new_node(bool *start_node, t_node_list **head,
				t_node_list *new_node);

/* PARSE NODE ERRORS - error_handling.c stops node
 creation and prints error to the terminal */
bool		pipe_error(t_tokens *token, bool check_pipestart,
				t_node_list *head, t_node_list *new_node);
bool		redir_error(t_tokens *token);

/* REDIR LIST CREATION - alloc_redir.c creates a
linked listof redirection structs for each node */
bool		parse_redir(t_tokens **token, t_node_list *new_node,
				int *redir_i, int *exit_code);
t_redir		*init_new_redir(t_tokens **token, int *exit_code);
bool		add_target(t_tokens *token, t_redir *redir);
void		append_new_redir(t_redir **head_redir, t_redir *curr_redir);

/* CMD STRUCT CREATION - after we parsed pipes and redird we create
 the cmd struct and assign cmd, args and n_option (if the command is echo) */
bool		parse_rest(t_tokens **token, t_node_list *new_node, t_msh **msh);
bool		alloc_cmd(t_node_list *curr_node, t_tokens *token, t_msh **msh);
bool		add_argument(char ***args, char *new_arg);
void		add_option_n(t_tokens **token, t_node_list *new_node);

/* FREEING FUNCTIONS FOR NODE AND MSH */
void		free_msh(t_msh *msh);
void		free_node_list(t_node_list *node_list);
void		free_cmd_struct(t_cmd *cmd);
void		free_redir_list(t_redir *head);

/* NODE PRINTING AND DEBUGGING */
char		*return_token_enum(int token_type);
char		*return_target_enum(int redir_type);
void		print_nodes(t_node_list *head);
void		print_exit_codes(t_msh	*msh);
void		print_null_cmd(void);
void		print_cmd_struct(t_cmd *cmd);
void		print_redir(t_redir *head);
void		print_nodes_file(t_node_list *head);
void		print_exit_codes_file(t_msh	*msh);
void		print_null_cmd_file(void);
void		print_cmd_struct_file(t_cmd *cmd);
void		print_redir_file(t_redir *head);

/* COMMUNICATION BETWEEN PARSING AND EXECUTION */
void		exec_node_list(t_node_list *node);

#endif
