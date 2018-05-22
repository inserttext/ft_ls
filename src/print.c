/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:39:52 by tingo             #+#    #+#             */
/*   Updated: 2018/05/22 12:34:45 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static size_t	count_items(const char *dir, struct s_options *opt)
{
	size_t size;
	DIR *dp;
	t_dirent *curr;

	size = 0;
	if (!(dp = opendir(dir)))
		return (0);
	while ((curr = readdir(dp)))
	{
		if (!opt->all && curr->d_name[0] == '.')
			continue ;
		size++;
	}
	closedir(dp);
	return (size);
}

void	chomp_root(t_node *dst, struct s_options *opt)
{
	size_t		size;
	DIR			*dp;
	t_dirent	*curr;

	if (!(size = count_items(dst->name, opt)))
		return ;
	if ((dst->children = (t_node **)ft_memalloc(sizeof(t_node *) * (size + 1)))
		&& (dp = opendir(dst->name)))
	{
		while ((curr = readdir(dp)))
		{
			if (!opt->all && curr->d_name[0] == '.')
				continue ;
			if (size)
				dst->children[--size] = node_create(curr, 0, opt);
			else
				break ;
		}
		closedir(dp);
	}
}

void	chomp_dir(t_node *dst, struct s_options *opt)
{
	size_t		size;
	DIR			*dp;
	t_dirent	*curr;

	if (!(size = count_items(dst->dirent->d_name, opt)))
		return ;
	if ((dst->children = (t_node **)ft_memalloc(sizeof(t_node *) * (size + 1)))
		&& (dp = opendir(dst->name)))
	{
		while ((curr = readdir(dp)))
		{
			if (!opt->all && curr->d_name[0] == '.')
				continue ;
			if (size)
				dst->children[--size] = node_create(curr, 0, opt);
			else
				break ;
		}
		closedir(dp);
	}
}

/* static t_dirent	**extend(t_dirent **list, t_dirent *new, size_t size) */
/* { */
/* 	t_dirent **ret; */

/* 	if ((ret = (t_dirent **)ft_memalloc(sizeof(t_dirent *) * (size + 2)))) */
/* 	{ */
/* 		ft_memcpy(ret, list, sizeof(t_dirent *) * size); */
/* 		ret[size] = new; */
/* 	} */
/* 	if (list) */
/* 		free(list); */
/* 	return (ret); */
/* } */

/* t_dirent	**ingestdir(const char *dir, struct s_options *opt) */
/* { */
/* 	DIR *dp; */
/* 	size_t size; */
/* 	t_dirent *curr; */
/* 	t_dirent **entries; */

/* 	size = 0; */
/* 	entries = 0; */
/* 	if ((dp = opendir(dir))) */
/* 	{ */
/* 		while ((curr = readdir(dp))) */
/* 		{ */
/* 			if (!opt->all && curr->d_name[0] == '.') */
/* 				continue ; */
/* 			if (!(entries = extend(entries, curr, size))) */
/* 				return (0); */
/* 			size += 1; */
/* 		} */
/* 		closedir(dp); */
/* 	} */
/* 	return (entries); */
/* } */

