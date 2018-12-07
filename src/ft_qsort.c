/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 01:31:33 by tingo             #+#    #+#             */
/*   Updated: 2018/12/06 20:09:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

#define WHILE(a) while(a);

static void	swap(struct s_file **a, struct s_file **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partt(struct s_file **lst, int lo, int hi, int reverse)
{
	struct s_file	*p;
	int				i;
	int				j;

	p = lst[lo];
	i = lo - 1;
	j = hi + 1;
	while (1)
	{
		if (!reverse)
		{
			WHILE((lst[++i]->stat.st_ctime - p->stat.st_ctime) > 0)
			WHILE((lst[--j]->stat.st_ctime - p->stat.st_ctime) < 0)
		}
		else
		{
			WHILE((lst[++i]->stat.st_ctime - p->stat.st_ctime) < 0)
			WHILE((lst[--j]->stat.st_ctime - p->stat.st_ctime) > 0)
		}
		if (i >= j)
			return (j);
		if (lst[i] != lst[j])
			swap(lst + i, lst + j);
	}
}

static int	partf(struct s_file **lst, int lo, int hi, int reverse)
{
	struct s_file	*p;
	int				i;
	int				j;

	p = lst[lo];
	i = lo - 1;
	j = hi + 1;
	while (1)
	{
		if (reverse)
		{
			WHILE(ft_strcmp(lst[++i]->name, p->name) > 0);
			WHILE(ft_strcmp(lst[--j]->name, p->name) < 0);
		}
		else
		{
			WHILE(ft_strcmp(lst[++i]->name, p->name) < 0);
			WHILE(ft_strcmp(lst[--j]->name, p->name) > 0);
		}
		if (i >= j)
			return (j);
		if (lst[i] != lst[j])
			swap(lst + i, lst + j);
	}
}

void		ft_qsortf(struct s_file **lst, int l, int h, struct s_opt o)
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
		p = o.time ? partt(lst, l, h, o.reverse) : partf(lst, l, h, o.reverse);
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
