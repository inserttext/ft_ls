/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:42:16 by tingo             #+#    #+#             */
/*   Updated: 2018/05/09 06:09:41 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	invalid_option(char c)
{
	ft_fprintf(1,
			"ls: invalid option -- '%c'\n"
			"try 'ls --help' for more information.\n", c);
	exit(2);
}
