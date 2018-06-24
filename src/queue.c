/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:38:13 by tingo             #+#    #+#             */
/*   Updated: 2018/06/03 11:23:13 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static inline struct s_pending	*new_node(struct s_fileinfo *data)
{
	struct s_pending *new;

	new = (struct s_pending *)ft_memalloc(sizeof(struct s_pending));
	new->data = data;
	return (new);
}

struct s_pending	*dequeue()
{
	struct s_pending *out;

	out = g_pending.head;
	g_pending.head = out->next;
	out->next = 0;
	return(out);
}

void	*enqueue(struct s_fileinfo *data)
{
	struct s_pending *new;

	new = new_node(data);
	if (g_pending.tail)
		g_pending.tail->next = new;
	g_pending.tail = new;
	if (!g_pending.head)
		g_pending.head = new;
}

void	free_node(struct s_pending *node)
{
	if (!node)
		return;
	if (node->data)
	{
		if (node->data->name)
			free(node->data->name);
		if (node->data->path)
			free(node->data->path);
		if (node->data->stat)
			free(node->data->stat);
		free(node->data);
	}
	free(node);
}
