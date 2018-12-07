/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 00:06:53 by marvin            #+#    #+#             */
/*   Updated: 2018/12/07 00:11:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"
#include "../includes/ft_qsort.h"

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

size_t	start(struct s_file ***f, char *p, DIR *d, struct s_opt *o)
{
	size_t i;

	if ((i = dir(f, p, d, o)))
		ft_qsortf(*f, 0, i - 1, *o);
	if (o->recursive)
		loaddir(*f, o);
	if (o->list)
		ft_printf("total %lu\n", o->blk);
	return (i);
}
