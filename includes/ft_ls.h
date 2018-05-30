/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:42:48 by tingo             #+#    #+#             */
/*   Updated: 2018/05/29 20:31:58 by tingo            ###   ########.fr       */
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
	sort_name,
	sort_time
};

typedef struct	s_argp
{
	char *name;
	char key;
	char *msg;
}				t_argp;

typedef struct	s_options
{
	int all;
	int reverse;
	int recursive;
	int sorttype;
	int longform;
}				t_options;

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

struct s_ntree	*new_node(const char *name, const char *dir);
void			fatten_children(struct s_ntree *node);
void			free_node(t_ntree **node);

void			ls_error(char *msg);

int				ls_core(struct s_ntree *root, struct s_options *opt);
void			ls_qsort(struct s_ntree **lst, int64_t l, int64_t h);
#endif
