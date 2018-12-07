/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 01:49:38 by tingo             #+#    #+#             */
/*   Updated: 2018/12/06 19:29:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QSORT_H
# define FT_QSORT_H

# include "ft_ls.h"

void	ft_qsortc(char **lst, int lo, int hi, struct s_opt o);
void	ft_qsortf(struct s_file **lst, int lo, int hi, struct s_opt o);

#endif
