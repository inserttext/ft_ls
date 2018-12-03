/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:54:52 by tingo             #+#    #+#             */
/*   Updated: 2018/12/02 20:25:45 by tingo            ###   ########.fr       */
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
	new = ft_calloc(sizeof(struct s_file*), size);
	ft_memcpy(new, *p, size * sizeof(struct s_file *));
	free(*p);
	*p = new;
	return (size);
}

static struct s_file	*new_file(const char *path, struct dirent *f)
{
	struct s_file *new;

	new = ft_calloc(sizeof(struct s_file), 1);
	new->name = ft_strjoin(path, "/");
	new->path = ft_strjoin(new->name, f->d_name);
	free(new->name);
	new->name = search(new->path, '/');
	return (new);
}

static size_t	dir(struct s_file ***lst, const char *p, DIR *d, struct s_opt o)
{
	struct dirent	*read;
	size_t 			i;
	size_t			size;

	i = 0;
	size = 11;
	*lst = ft_calloc(sizeof(struct s_file*), size);
	while ((read = readdir(d)) != 0)
	{
		if (!(read->d_name[0] == '.') || o.all)
		{
			*lst[i] = new_file(p, read);
			if (++i == size)
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
	i = dir(&f, p, d, *o);
	ft_qsortf(f, 0, i, *o);
	ft_printf("%s\n", p);
	i = -1;
	while (f[++i])
	{
		print(*f[i], o, !f[i + 1]);
		free(f[i]->path);
		free(f[i]);
	}
	free(f);
	return (0);
}
