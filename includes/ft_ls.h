/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:42:48 by tingo             #+#    #+#             */
/*   Updated: 2018/05/15 20:38:51 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>

# define ALL ((uint64_t)1<<('a'-'A'))
# define LNG ((uint64_t)1<<('l'-'A'))
# define TME ((uint64_t)1<<('t'-'A'))
# define RCR ((uint64_t)1<<('R'-'A'))
# define RVR ((uint64_t)1<<('r'-'A'))

# define FLAG_MASK (ALL|LNG|TME|RCR|RVR)

void	quick_sort(char **list, size_t low, size_t high);
void	rquick_sort(char **list, size_t low, size_t high);
void	invalid_option(char c);

int		ls_core(uint64_t flags, char ***list);
char	**listextend(char **list, char **item, size_t amt);
size_t	countarg(char **arg);

#endif
