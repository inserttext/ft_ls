/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 23:47:35 by tingo             #+#    #+#             */
/*   Updated: 2018/05/15 00:56:04 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char **listextend(char **list, char **item, size_t amt)
{
	char			**out;
	static size_t	size = 0;

	if ((out = (char **)ft_memalloc(sizeof(char *) * (size + (amt + 1)))))
	{
		if (list)
		{
			ft_memcpy(out, list, sizeof(char *) * size);
			free(list);
		}
		if (*item)
			ft_memcpy(out + size, item, sizeof(char *) * amt);
		size += amt;
	}
	return (out);
}

size_t	countarg(char **arg)
{
	size_t size;

	size = 0;
	while (arg[size])
		size += 1;
	return (size);
}
