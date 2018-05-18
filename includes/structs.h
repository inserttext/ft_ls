/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:23:00 by tingo             #+#    #+#             */
/*   Updated: 2018/05/17 20:59:23 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_STRUCTS_H
# define LS_STRUCTS_H

typedef struct	s_argp
{
	char *name;
	char *key;
	char *msg;
}				t_argp;

struct			s_options
{
	int all;
	int reverse;
	int recursive;
	int time;
	int longform;
};

#endif
