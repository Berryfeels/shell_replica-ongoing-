#include "../../include/minishell.h"

static void	free_results(char **results)
{
	int	i;

	i = 0;
	while (results[i]) 
	{
		free(results[i++]);
	}
	free(results);
}

static char	*ft_eiterate(char **path, char **envp_paths, char *cmd)
{
	char	*add_slash;
	int		i;

	i = 0;
	while (envp_paths[i])
	{
		add_slash = ft_strjoin (envp_paths[i], "/");
		if (add_slash == NULL)
			return (NULL);
		(*path) = ft_strjoin (add_slash, cmd);
		if (*path == NULL)
			return (NULL);
		free(add_slash);
  		//fprintf(stderr, "Testing path: %s\n", *path);
		if (access (*path, X_OK) == 0)
			return (*path);
		free(*path);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**envp_paths;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr (envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i]) 
	{
		perror("PATH not found in environment variables");
		return (NULL);
	}
	envp_paths = ft_split (envp[i] + 5, ':');
	if (!envp_paths) 
	{
		perror ("Error: ft_split failed\n");
		return (NULL);
	}
	path = ft_eiterate(&path, envp_paths, cmd);
	free_results(envp_paths);
	if (path != NULL)
		return (path);
	return (0);
}

int exec_external_cmd(t_token *tokens, t_job *job)
{
    char	*cmd_path;
	int		i;

    if (!tokens || !tokens[0].value)
        return -1;

    cmd_path = find_path(tokens[0].value, g_msh.env);
    if (!cmd_path)
    {
        ft_printf("Command not found: %s\n", tokens[0].value);
        return -1;
    }

    job->pid = fork();
	
    if (job->pid == -1)
    {
        perror("fork");
        free(cmd_path);
        return -1;
    }
    else if (job->pid == 0)
    {
		i = 0;
		char	*av[i + 1];
        while (tokens[i].value != NULL)
		{
			av[i] = tokens[i].value;
			i++;
		}
		if (execve(cmd_path, av, g_msh.env) == -1)
        {
            perror("execve");
            free(cmd_path);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
		job->status = 1;
		job->command = strdup(tokens[0].value);
        waitpid(job->pid, &job->status, 0);
        free(cmd_path);
		job->status = 0;
    }

    return 0;
}