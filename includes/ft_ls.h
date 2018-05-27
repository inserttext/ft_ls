/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:42:48 by tingo             #+#    #+#             */
/*   Updated: 2018/05/26 20:39:03 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <errno.h>
# include <error.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct	s_argp
{
	char *name;
	char key;
	char *msg;
}				t_argp;

typedef struct	s_fileinfo
{
	char			*name;
	char			*fullname;
	int				type;
	ino_t			inode;
	struct stat		*stat;
	struct dirent	*dirent;
}				t_fileinfo;

typedef struct	s_ntree
{
	size_t				size;
	size_t				fill;
	struct s_fileinfo	*data;
	struct s_ntree		**children;
}				t_ntree;

struct			s_options
{
	int all;
	int reverse;
	int recursive;
	int time;
	int longform;
};
void	ls_error(char *msg);
#endif
