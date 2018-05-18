/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:01:39 by tingo             #+#    #+#             */
/*   Updated: 2018/05/15 15:26:27 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	quick_sort(char **list, size_t low, size_t high)
{
	char   *pivot;
	size_t i;
	size_t j;

	pivot = list[(low + high) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (ft_strcmp(list[i], pivot) < 0 && i < high)
			i++;
		while (ft_strcmp(list[j], pivot) > 0 && j > low)
			j--;
		if (i <= j)
		{
			if (list[i] != list[j])
				SWAP(((uintptr_t *)list)[i], ((uintptr_t *)list)[j]);
			i++;
			j--;
		}
	}
	if (j > low)
		quick_sort(list, low, j);
	if (i < high)
		quick_sort(list, i, high);
}

void	rquick_sort(char **list, size_t low, size_t high)
{
	char   *pivot;
	size_t i;
	size_t j;

	pivot = list[(low + high) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (ft_strcmp(list[i], pivot) > 0 && i < high)
			i++;
		while (ft_strcmp(list[j], pivot) < 0 && j > low)
			j--;
		if (i <= j)
		{
			if (list[i] != list[j])
				SWAP(((uintptr_t *)list)[i], ((uintptr_t *)list)[j]);
			i++;
			j--;
		}
	}
	if (j > low)
		rquick_sort(list, low, j);
	if (i < high)
		rquick_sort(list, i, high);
}
