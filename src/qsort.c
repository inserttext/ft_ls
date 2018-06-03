/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:51:37 by tingo             #+#    #+#             */
/*   Updated: 2018/05/30 21:23:00 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static inline void	swap(void **a, void **b)
{
	void *swap;

	if (*a != *b)
	{
		swap = *a;
		*a = *b;
		*b = swap;
	}
}
static int64_t		partition(struct s_fileinfo **list, int64_t l, int64_t h)
{
	char	*cmp;
	int64_t	i;
	int64_t	j;

	i = l - 1;
	j = 1;
	cmp = list[h]->name;
	while (j <= h - 1)
	{
		if (ft_strcmp(list[j]->name, cmp) < 0)
		{
			i++;
			swap((void **)list + j, (void **)list + i);
		}
		j++;
	}
	swap((void **)list + i + 1, (void **)list + h);
	return (i + 1);
}

void				ls_qsort(struct s_fileinfo **lst, int64_t l, int64_t h)
{
	int64_t *stack;
	int64_t top;
	int64_t p;

	top = 0;
	stack = (int64_t *)ft_memalloc(sizeof(int64_t) * (h - l + 1));
	stack[++top] = l;
	stack[++top] = h;
	while (top > 0)
	{
		h = stack[top--];
		l = stack[top--];
		p = partition(lst, l, h);
		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - l;
		}
		if (p + 1 < h)
		{
			stack[++top] = p + l;
			stack[++top] = h;
		}
	}
	free(stack);
}
