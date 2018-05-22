/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:42:48 by tingo             #+#    #+#             */
/*   Updated: 2018/05/22 12:35:49 by tingo            ###   ########.fr       */
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

typedef struct dirent t_dirent;

enum			e_sorttype
{
	unknown,
	sort_name,
	sort_time
};

typedef struct	s_node
{
	char			*name;
	t_dirent	 	*dirent;
	struct stat		*stat;
	struct s_node	**children;
}				t_node;

struct			s_options
{
	unsigned int	all;
	unsigned int	longform;
	unsigned int	recursive;
	unsigned int	sort_reverse;
	unsigned int	sort_type;
};

t_node			*node_create(t_dirent *data, char *name, struct s_options *opt);
t_node			**child_extend(t_node **, t_node *, size_t);
void			node_destroy(t_node *);

/* t_dirent		**ingestdir(const char *, struct s_options *); */
void	chomp_root(t_node *dst, struct s_options *opt);
void	chomp_dir(t_node *dst, struct s_options *opt);
void	ft_perror(char *msg);

#endif
