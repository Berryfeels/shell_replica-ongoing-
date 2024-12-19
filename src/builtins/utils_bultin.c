#include "../../include/minishell.h"

int execute_command(char **av, bld_in *builtins)
{
    bld_in  *builtin;
    
    if (av[0] == NULL)
        return (1);
    builtin = find_builtin(builtins, av[0]);
    if (builtin)
        builtin->func(av);
    if (execvp(av[0], av) == -1)
    {
        fprintf (stderr, "Mestepum: command not found: %s\n", av[0]);
        return (127);
    }
    return (0);
}

bld_in  *find_builtin(bld_in *head, const char *command)
{
    while (head != NULL)
    {
        if (strcmp (head->name, command) == 0)
            return (head);
        head = head->next;
    }
    return (NULL);
}
