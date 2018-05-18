/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:24:27 by tingo             #+#    #+#             */
/*   Updated: 2018/05/17 20:58:22 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_argp g_arglist[] = {
	{"all", "a", "do not ignore files starting with ."},
	{"long", "l", "use a long listing format"},
	{"recursive", "R", "display subdirectories recursively"},
	{"reverse", "r", "reverse order while sorting"},
	{"time", "t", "sort by modification time, newest first"}
};

int	main(int argc, char **argv)
{
	char **list;
	struct s_options opt;

	ft_bzero(&opt, sizeof(struct s_options));
	if (argc > 1)
}
