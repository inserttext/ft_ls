/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:05:05 by tingo             #+#    #+#             */
/*   Updated: 2018/10/18 18:12:43 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

struct	s_node
{
	const char*		name;
	struct s_node	*list;
};

struct	s_opt
{
	int list;
	int recursive;
	int all;
	int reverse;
	int time;
};

#endif
