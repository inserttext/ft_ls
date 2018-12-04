/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 19:51:59 by tingo             #+#    #+#             */
/*   Updated: 2018/12/03 15:54:33 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"
#include "../includes/ft_qsort.h"

static void			error(int c)
{
	ft_fprintf(2, "ft_ls: invalid option -- '%c'\n", c);
	exit(1);
}

static struct s_opt	flags(int argc, int *ind, char **argv)
{
	struct s_opt	opt;

	*ind = 0;
	opt = (struct s_opt){0};
	while (++*ind < argc && *argv[*ind] == '-')
	{
		if (!ft_strcmp((argv[*ind]), "--"))
		{
			++*ind;
			return (opt);
		}
		while (*++argv[*ind])
		{
			MATCH(*argv[*ind] == 'l', opt.list = 1);
			OR(*argv[*ind] == 'R', opt.recursive = 1);
			OR(*argv[*ind] == 'a', opt.all = 1);
			OR(*argv[*ind] == 'r', opt.reverse = 1);
			OR(*argv[*ind] == 't', opt.time = 1);
			OTHERWISE(error(*argv[*ind]));
		}
	}
	return (opt);
}

static void			prep(char **lst, struct s_opt *o)
{
	int i;
	struct stat s;

	i = -1;
	while(lst[++i])
	{
		if (!lstat(lst[i], &s))
		{
			if (S_ISDIR(s.st_mode))
				push(lst[i], o);
			else
				print((struct s_file){lst[i], lst[i], s}, o, !lst[i + 1]);
		}
		else
			ft_fprintf(2, "ft_ls: cannot access '%s'\n", lst[i]);
	}
	free(lst);
}

static int			ft_ls(char **lst, struct s_opt o)
{
	char		*p;

	prep(lst, &o);
	while ((p = pop(&o)))
	{
		if (expandd(p, &o))
			ft_fprintf(2, "ft_ls: cannot access '%s'\n", p);
		free(p);
	}
	return (0);
}

int					main(int argc, char *argv[])
{
	int				ind;
	char			**lst;
	int				size;
	struct s_opt	opt;

	opt = flags(argc, &ind, argv);
	size = argc - ind;
	lst = ft_calloc(sizeof(char*), size + 2);
	if (ind == argc)
		lst[0] = ".";
	else
		while (ind < argc)
		{
			lst[argc - ind - 1] = argv[ind];
			ind++;
		}
	ft_qsortc(lst, 0, size ? size - 1 : 0, opt);
	return (ft_ls(lst, opt));
}
