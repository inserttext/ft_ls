/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:24:27 by tingo             #+#    #+#             */
/*   Updated: 2018/06/03 11:21:59 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void assign(const char *s, struct s_options *opt)
{
	while (*++s)
	{
		if (*s == 'l')
			opt->longform = 1;
		else if (*s == 'a')
			opt->all = 1;
		else if (*s == 'R')
			opt->recursive = 1;
		else if (*s == 'r')
			opt->reverse = 1;
		else if (*s == 't')
			opt->sorttype = sort_time;
		else
		{
			ft_fprintf(2, "ft_ls: argument \'%c\' does not exist\n", *s);
			exit(2);
		}
	}
}

static size_t	argparse(int argc, char **argv, struct s_options *opt)
{
	int i;
	int out;

	i = 1;
	out = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-' && !argv[i][2])
			{
				out = out ? out : i + 1;
				break ;
			}
			assign(argv[i], opt);
		}
		else if (!out)
			out = i;
		i++;
	}
	return (out ? out : i);
}

int	main(int argc, char **argv)
{
	int					i;
	int					ret;
	struct s_options	opt;

	i = argparse(argc, argv, &opt);
	if (!(argc - i))
	return (ret);
}
