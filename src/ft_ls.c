/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:24:27 by tingo             #+#    #+#             */
/*   Updated: 2018/05/22 09:15:18 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	main(int argc, char *argv[])
{
	struct s_options opt;
	t_node thing;
	t_dirent **list;

	opt.all = 0;
	thing.data = 0;
	if (argc > 1)
	{
		write(1, "\n", 1);
	}
	return (0);
}
