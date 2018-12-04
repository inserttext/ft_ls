/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:54:52 by tingo             #+#    #+#             */
/*   Updated: 2018/12/03 16:10:07 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"
#include "../includes/ft_qsort.h"

static char*			search(char* s, char c)
{
	size_t len;

	len = ft_strlen(s);
	while (len--)
		if (s[len] == c)
			return (s + len + 1);
	return (0);
}

static size_t			extend(struct s_file ***p, size_t size)
{
	struct s_file	**new;

	size += 10;
	new = ft_calloc(size, sizeof(struct s_file *));
	ft_memcpy(new, *p, (size - 10) * sizeof(struct s_file *));
	free(*p);
	*p = new;
	return (size);
}

static struct s_file	*new_file(const char *path, struct dirent *f)
{
	struct s_file *new;

	new = ft_calloc(1, sizeof(struct s_file));
	new->name = ft_strjoin(path, "/");
	new->path = ft_strjoin(new->name, f->d_name);
	free(new->name);
	new->name = search(new->path, '/');
	lstat(new->path, &new->stat);
	return (new);
}

static size_t			dir(struct s_file ***lst, const char *p, DIR *d,
							struct s_opt *o)
{
	struct dirent	*read;
	size_t 			i;
	size_t			size;

	i = 0;
	size = 10;
	o->blk = 0;
	*lst = ft_calloc(size, sizeof(struct s_file *));
	while ((read = readdir(d)) != 0)
	{
		if (read->d_name[0] != '.' || o->all)
		{
			(*lst)[i] = new_file(p, read);
			o->blk += (*lst)[i++]->stat.st_blocks;
			if (i == size)
				size = extend(lst, size);
		}
	}
	return (i - 1);
}

int						expandd(const char *p, struct s_opt *o)
{
	DIR				*d;
	struct s_file	**f;
	size_t			i;

	if (!(d = opendir(p)))
		return (1);
	i = dir(&f, p, d, o);
	ft_qsortf(f, 0, i, *o);
	ft_printf("%s:\n", p);
	if (o->list)
		ft_printf("total %lu\n", o->blk/2);
	i = -1;
	while (f[++i])
	{
		if (o->recursive && S_ISDIR(f[i]->stat.st_mode) &&
			ft_strcmp(f[i]->name, "..") && ft_strcmp(f[i]->name, "."))
			push(f[i]->path, o);
		print(*(f[i]), o, !f[i + 1]);
		free(f[i]->path);
		free(f[i]);
	}
	closedir(d);
	free(f);
	return (0);
}
