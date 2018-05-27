/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:46:36 by tingo             #+#    #+#             */
/*   Updated: 2018/05/26 20:40:05 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct s_ntree	*new_node(const char *name, const char *dir)
{
	struct s_ntree *new;

	if (!(new = (t_ntree *)ft_memalloc(sizeof(t_ntree)))
		|| !(new->data = (t_fileinfo *)ft_memalloc(sizeof(t_fileinfo)))
		|| !(new->children = (t_ntree **)ft_memalloc(sizeof(t_ntree *))))
		ls_error("ft_ls: Unable to allocate new node");
	new->data->name = ft_strdup(name);
	new->data->fullname = ft_strjoin(dir ? ft_strjoin(dir, "/") : "./", name);
	new->size = 32;
	new->fill = 0;
	if (lstat(new->data->fullname, new->data->stat))
		ls_error(0);
	return (new);
}

void			expand_children(struct s_ntree *node)
{
	t_ntree **new;

	if (!(new = (t_ntree **)ft_memalloc(sizeof(t_ntree *) * node->size * 2)))
		ls_error("ft_ls: Unable to expand children");
	ft_memcpy(new, node->children, node->fill * sizeof(t_ntree *));
	free(node->children);
	node->children = new;
	node->size *= 2;
}

void			free_node(t_ntree **node)
{
	if ((*node)->data)
	{
		if ((*node)->data->name)
			free((*node)->data->name);
		if ((*node)->data->fullname)
			free((*node)->data->fullname);
		free((*node)->data);
	}
	if ((*node)->children)
		free((*node)->children);
	free(*node);
	*node = 0;
}
