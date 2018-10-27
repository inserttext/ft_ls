/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 01:31:33 by tingo             #+#    #+#             */
/*   Updated: 2018/10/25 15:15:32 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

static int	part(char **lst, int lo, int hi, int reverse)
{
	char	*p;
	int		i;
	int		j;

	p = lst[lo];
	i = lo - 1;
	j = hi + 1;
	while (1)
	{
		if (reverse)
		{
			while (ft_strcmp(lst[++i], p) > 0);
			while (ft_strcmp(lst[--j], p) < 0);
		}
		else
		{
			while (ft_strcmp(lst[++i], p) < 0);
			while (ft_strcmp(lst[--j], p) > 0);
		}
		if (i >= j)
			return (j);
		if (lst[i] != lst[j])
			SWAP(*(uintptr_t *)(lst + i), *(uintptr_t *)(lst + j));
	}
}

void		ft_qsort(char **lst, int l, int h, int reverse)
{
	int	stack[h - l + 1];
	int	top;
	int	p;

	top = -1;
	stack[++top] = l;
	stack[++top] = h;
	while (top >= 0)
	{
		h = stack[top--];
		l = stack[top--];
		p = part(lst, l, h, reverse);
		if (p > l)
		{
			stack[++top] = l;
			stack[++top] = p;
		}
		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}
