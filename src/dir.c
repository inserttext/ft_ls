/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:54:52 by tingo             #+#    #+#             */
/*   Updated: 2018/12/07 00:11:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"
#include "../includes/ft_qsort.h"

#define COND (o->multi || o->recursive)

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

static struct s_file	*new_file(char *path, struct dirent *f)
{
	struct s_file	*new;
	int				flag;

	flag = path[ft_strlen(path) - 1] == '/';
	new = ft_calloc(1, sizeof(struct s_file));
	new->name = flag ? path : ft_strjoin(path, "/");
	new->path = ft_strjoin(new->name, f->d_name);
	if (!flag)
		free(new->name);
	new->name = search(new->path, '/');
	lstat(new->path, &new->stat);
	return (new);
}

size_t					dir(struct s_file ***lst, char *p, DIR *d,
							struct s_opt *o)
{
	struct dirent	*read;
	size_t 			i;
	size_t			size;

	i = 0;
	size = 20;
	o->blk = 0;
	*lst = ft_calloc(size, sizeof(struct s_file *));
	while ((read = readdir(d)) != 0)
	{
		if (read->d_name[0] != '.' || o->all)
		{
			(*lst)[i] = new_file(p, read);
			o->blk += (*lst)[i++]->stat.st_blocks;
			if (i == size - 1)
				size = extend(lst, size);
		}
	}
	return (i);
}

int						expandd(char *p, struct s_opt *o)
{
	DIR				*d;
	struct s_file	**f;
	size_t			i;

	if (!(d = opendir(p)))
		return (1);
	ft_printf("%c%s%s", o->first ? '\n' : 0, COND ? p : "", COND ? ":\n" : "");
	i = start(&f, p, d, o);
	if (i)
	{
		i = -1;
		while (f[++i])
		{
			print(*(f[i]), o, !f[i + 1]);
			free(f[i]->path);
			free(f[i]);
		}
	}
	closedir(d);
	free(f);
	o->first = 1;
	return (0);
}
