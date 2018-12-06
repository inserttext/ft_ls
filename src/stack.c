/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 06:30:32 by tingo             #+#    #+#             */
/*   Updated: 2018/12/06 04:23:27 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

int		push(const char *name, struct s_opt *p)
{
	struct s_node *n;

	if ((n = (struct s_node *)ft_calloc(1, sizeof(struct s_node))))
	{
		n->name = ft_strdup(name);
		n->next = p->top;
		p->top = n;
		return (0);
	}
	return (1);
}

static int		ppush(const char *name, struct s_opt *p)
{
	struct s_node *n;

	if ((n = (struct s_node *)ft_calloc(1, sizeof(struct s_node))))
	{
		n->name = ft_strdup(name);
		n->next = p->rtop;
		p->rtop = n;
		return (0);
	}
	return (1);
}

static void		npush(struct s_opt *p)
{
	struct s_node *t;

	while(p->rtop)
	{
		t = p->rtop->next;
		p->rtop->next = p->top;
		p->top = p->rtop;
		p->rtop = t;
	}
}

int				loaddir(struct s_file **f, struct s_opt *p)
{
	int i;

	i = -1;
	while (f[++i])
	{
		if (S_ISDIR(f[i]->stat.st_mode) && ft_strcmp(f[i]->name, "..")
				&& ft_strcmp(f[i]->name, "."))
			ppush(f[i]->path, p);
	}
	npush(p);
	return (0);
}

char			*pop(struct s_opt *p)
{
	char			*r;
	struct s_node	*t;

	if (p->top)
	{
		r = p->top->name;
		t = p->top;
		p->top = p->top->next;
		free(t);
		return (r);
	}
	return (0);
}
