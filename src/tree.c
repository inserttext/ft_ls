/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 22:02:20 by tingo             #+#    #+#             */
/*   Updated: 2018/05/22 12:33:09 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_node	*node_create(t_dirent *data, char *name, struct s_options *opt)
{
	t_node *new;

	if ((new = (t_node *)ft_memalloc(sizeof(t_node))) && (data || name))
	{
		if (data)
		{
			new->dirent = data;
			new->name = data->d_name;
		}
		else if (name)
			new->name = name;
	}
	if (opt->longform)
		if ((errno = stat(new->name, new->stat)))
			ft_perror(0);
	return (new);
}

void	node_destroy(t_node *node)
{
	if (!node)
		return ;
	if (node->children)
		free(node->children);
	free(node);
}

t_node **child_extend(t_node **list, t_node *new, size_t size)
{
	t_node **ret;

	if ((ret = (t_node **)ft_memalloc(sizeof(t_node *) * (size + 2))))
	{
		ft_memcpy(ret, list, sizeof(t_node *) * size);
		ret[size] = new;
	}
	if (list)
		free(list);
	return (ret);
}
