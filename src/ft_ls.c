/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:45:03 by tingo             #+#    #+#             */
/*   Updated: 2018/05/15 20:38:35 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char **parse_arg(char **arg, uint64_t *flags)
{
	char	**list;

	list = 0;
	while (*++arg)
	{
		if ((*arg)[0] == '-' && (*arg)[1])
		{
			if ((*arg)[1] == '-' && !(*arg)[2])
				break ;
			while (*(++(*arg)))
			{
				if (**arg >= 'A' && ((uint64_t)1 << (**arg - 'A')) & FLAG_MASK)
					*flags |= (uint64_t)1 << (**arg - 'A');
				else
					invalid_option(**arg);
			}
		}
		else if (!(list = listextend(list, arg, 1)))
			return (0);
	}
	if (*arg)
		list = listextend(list, arg, countarg(arg));
	return (list);
}

int	main(int argc, char **argv)
{
	uint64_t	flag;
	char		**list;

	flag = 0;
	list = 0;
	if (argc > 1)
		list = parse_arg(argv, &flag);
	ls_core(flag, &list);
	free(list);
	return (0);
}
