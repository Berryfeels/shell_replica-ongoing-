#include "libft.h"

void    ft_free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free (tab[i]);
        i++;
    }
    free (tab);
}