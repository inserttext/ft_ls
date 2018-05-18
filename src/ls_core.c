/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 22:31:07 by tingo             #+#    #+#             */
/*   Updated: 2018/05/15 20:50:17 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char **bufinit()
{
	char **buf;

	if ((buf = ft_memalloc(sizeof(char *) * 2)))
		buf[0][0] = '.';
	return (buf);
}

int	ls_core(uint64_t flags, char ***list)
{
	DIR *dp;
	struct dirent *dir;

	if (!*list)
		*list = bufinit();
	if (flags & RVR)
		rquick_sort(*list, 0, countarg(*list) - 1);
	else
		quick_sort(*list, 0, countarg(*list) - 1);
	for (int i = 0; (*list)[i]; i++)
	{
		if ((dp = opendir((*list)[i])))
			while ((dir = readdir(dp)))
				ft_printf("%s  ", dir->d_name);
	}
	return (0);
}
