/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 19:51:59 by tingo             #+#    #+#             */
/*   Updated: 2018/10/18 20:11:33 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

#define MATCH(a,b) if (a)b
#define OR(a,b) else if (a)b
#define OTHERWISE(a) else (a)

static struct s_opt	flags(int argc, char ***argv)
{
	int				i;
	struct s_opt	opt;

	i = 0;
	opt = (struct s_opt){0, 0, 0, 0, 0};
	while (++i < argc && (*++*argv)[0] == '-')
	{
		if (!ft_strcmp((**argv), "--"))
			break ;
		while (*++**argv)
		{
			MATCH(***argv == 'l', opt.list = 1);
			OR(***argv == 'R', opt.recursive = 1);
			OR(***argv == 'a', opt.all = 1);
			OR(***argv == 'r', opt.reverse = 1);
			OR(***argv == 't', opt.time = 1);
			OTHERWISE(exit(0));
		}
	}
	return (opt);
}

int	main(int argc, char *argv[])
{
	flags(argc, &argv);
	printf("%c", **argv);
	return (0);
}

/*
** static struct s_opt	flags(int argc, char **argv)
** {
** 	int				i;
** 	struct s_opt	opt;
**
** 	i = 1;
** 	opt = (struct s_opt){0, 0, 0, 0, 0};
** 	while (i < argc && argv[i][0] == '-')
** 	{
** 		if (!ft_strcmp(argv[i], "--"))
** 			break ;
** 		while (*argv[i])
** 		{
** 			if (*argv[i] == 'l')
** 				opt.list = 1;
** 			else if (*argv[i] == 'R')
** 				opt.recursive = 1;
** 			else if (*argv[i] == 'a')
** 				opt.all = 1;
** 			else if (*argv[i] == 'r')
** 				opt.reverse = 1;
** 			else if (*argv[i] == 't')
** 				opt.time = 1;
** 			else
** 				exit(0);
** 			argv[i]++;
** 		}
** 		i++;
** 	}
** 	return (opt);
** }
*/
