/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 06:30:32 by tingo             #+#    #+#             */
/*   Updated: 2018/10/28 02:21:25 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

int		push(const char *name, struct s_opt *p)
{
	struct s_node *n;

	if ((n = (struct s_node*)ft_calloc(sizeof(struct s_node), 1)))
	{
		n->name = ft_strdup(name);
		n->next = p->top;
		p->top = n;
		return (0);
	}
	return (1);
}

char	*pop(struct s_opt *p)
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
