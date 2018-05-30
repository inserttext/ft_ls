/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:42:48 by tingo             #+#    #+#             */
/*   Updated: 2018/05/30 15:47:44 by tingo            ###   ########.fr       */
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

enum			e_filetype
{
    unknown,
    fifo,
    chardev,
    directory,
    blockdev,
    normal,
    symbolic_link,
    sock,
    whiteout,
    arg_directory
};

enum			e_sorttype
{
	sort_none = -1,
	sort_name,
	sort_time
};

typedef struct	s_options
{
	int				all;
	int				reverse;
	int				recursive;
	int				longform;
	enum e_sorttype sorttype;
}				t_options;

typedef struct	s_fileinfo
{
	char			*name;
	char			*path;
	ino_t			inode;
	enum e_filetype filetype;
	struct stat		*stat;
}				t_fileinfo;

typedef struct	s_pending
{
	struct s_fileinfo	*data;
	struct s_pending	*next;
}				t_pending;

typedef struct	s_queue
{
	t_pending *head;
	t_pending *tail;
}				t_queue;

t_queue			*g_pending;

void			ls_error(char *msg);
#endif
