/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsortc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 01:31:33 by tingo             #+#    #+#             */
/*   Updated: 2018/12/02 20:02:39 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

static void swap(char **a, char **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	timecmp(char *a, char *b)
{
	struct stat sa;
	struct stat sb;

	stat(a, &sa);
	stat(b, &sb);

	return (sa.st_ctime - sb.st_ctime);
}
static int	partt(char **lst, int lo, int hi, int reverse)
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
			while (timecmp(lst[++i], p) > 0);
			while (timecmp(lst[--j], p) < 0);
		}
		else
		{
			while (timecmp(lst[++i], p) < 0);
			while (timecmp(lst[--j], p) > 0);
		}
		if (i >= j)
			return (j);
		if (lst[i] != lst[j])
			swap(lst + i, lst + j);
	}
}


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
			swap(lst + i, lst + j);
	}
}

void		ft_qsortc(char **lst, int l, int h, struct s_opt o)
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
		p = o.time ? partt(lst, l, h, o.reverse) : part(lst, l, h, o.reverse);
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
