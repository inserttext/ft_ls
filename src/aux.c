#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

static void	collapse(char **lst, int size)
{
	int a;
	int b;

	a = 0;
	while (a < size && lst[a])
		a++;
	b = a;
	while (a < size)
	{
		if (!lst[a])
		{
			while (b < size && !lst[b])
				b++;
			if (b >= size)
				return;
			else
			{
				lst[a] = lst[b];
				lst[b] = 0;
			}
		}
		a++;
	}
}

int			verify(char	**lst)
{
	int		i;
	struct stat s;

	i = -1;
	while (lst[++i])
		if (lstat(lst[i], &s))
		{
			ft_fprintf(2, "ft_ls: cannot access '%s'\n", lst[i]);
			lst[i] = 0;
		}
	collapse(lst, i);
	i = -1;
	while (lst[++i])
		;
	return (i);
}
