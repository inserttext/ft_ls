/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 06:30:32 by tingo             #+#    #+#             */
/*   Updated: 2018/10/24 11:34:22 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

static size_t			count(char *name)
{
	DIR		*d;
	size_t	i;

	i = 0;
	if (!(d = opendir(name)))
		return (0);
	while(readdir(d))
		i++;
	closedir(d);
	return (i);
}

static struct dirent	**expand(char *name)
{
	DIR				*dir;
	size_t			i;
	struct dirent	**d;

	if (!(i = count(name)))
		return (0);
	d = ft_calloc(sizeof(struct dirent*), i + 1);
	i = 0;
	dir = opendir(name);
	while ((d[i++] = readdir(dir)));
	return (d);

}

struct s_node			*new_node(char *name)
{
	struct s_node *n;

	n = ft_calloc(sizeof(n), 1);
	n->s = ft_calloc(sizeof(struct stat), 1);
	if (stat(name, n->s) < 0)
	{
		free(n->s);
		free(n);
		return (0);
	}
	n->long_name = ft_strdup(name);
	return (n);
}

struct s_node			**populate(char *name)
{
	struct dirent	**d;
	struct s_node	**o;
	char			*t1;
	char			*t2;
	size_t			i;

	i = -1;
	d = expand(name);
	while (d[++i]);
	o = ft_calloc(sizeof(struct s_node*), i + 1);
	i = -1;
	while (d[++i])
	{
		t1 = ft_strjoin(name, d[i]->d_name);
		o[i] = new_node((t2 = ft_strjoin(t1, "/")));
		free(t1);
		free(t2);
	}
	free(d);
	return (o);
}

void					free_node(struct s_node *p)
{
	if (p)
	{
		if (p->s)
			free(p->s);
		if (p->list)
			free(p->list);
		if (p->long_name)
			free(p->long_name);
		free(p);
	}
}
