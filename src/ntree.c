/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:46:36 by tingo             #+#    #+#             */
/*   Updated: 2018/05/29 18:20:29 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct s_ntree	*new_node(const char *name, const char *dir)
{
	struct s_ntree	*n;
	char			*tmp;

	tmp = 0;
	if (!(n = (t_ntree *)ft_memalloc(sizeof(t_ntree)))
		|| !(n->data = (t_fileinfo *)ft_memalloc(sizeof(t_fileinfo)))
		|| !(n->data->stat = (struct stat *)ft_memalloc(sizeof(struct stat)))
		|| !(n->children = (t_ntree **)ft_memalloc(sizeof(t_ntree *) * 10)))
		ls_error("ft_ls: Unable to allocate n node");
	n->data->name = name ? ft_strdup(name) : 0;
	if (name && dir)
		n->data->fullname = ft_strjoin((tmp = ft_strjoin(dir, "/")), name);
	else
		n->data->fullname = name ? ft_strdup(name) : 0;
	n->size = 10;
	n->fill = 0;
	if (name && lstat(n->data->fullname, n->data->stat))
			ls_error(0);
	if (tmp)
		free(tmp);
	return (n);
}

void			fatten_children(struct s_ntree *node)
{
	t_ntree **new;

	if (!(new = (t_ntree **)ft_memalloc(sizeof(t_ntree *) * node->size * 2)))
		ls_error("ft_ls: Unable to fatten children (out of cake)");
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
		if ((*node)->data->stat)
			free((*node)->data->stat);
		free((*node)->data);
	}
	if ((*node)->children)
		free((*node)->children);
	free(*node);
	*node = 0;
}
