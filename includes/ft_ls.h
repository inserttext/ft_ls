/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:05:05 by tingo             #+#    #+#             */
/*   Updated: 2018/10/25 14:39:48 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>

# define MATCH(a,b) if (a)b
# define OR(a,b) else if (a)b
# define OTHERWISE(a) else (a)

struct	s_node
{
	char*			name;
	struct s_node	*next;
};

struct	s_opt
{
	int				list;
	int				recursive;
	int				all;
	int				reverse;
	int				time;
	struct s_node	*top;
};

int		push(const char *name, struct s_opt *p);
char	*pop(char *name, struct s_opt *p);

#endif
