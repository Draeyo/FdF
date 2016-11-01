/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 14:51:44 by vlistrat          #+#    #+#             */
/*   Updated: 2016/09/15 13:45:25 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}

static void		free_coord(int **coord)
{
	int		i;

	i = 0;
	while (coord[i])
	{
		free(coord[i]);
		i++;
	}
}

void			ft_free_listes(t_fdf *lst, t_pnt *addr, t_img *image)
{
	if (MAP)
	{
		free_map(MAP);
		free(MAP);
	}
	if (TMP)
	{
		free_map(TMP);
		free(TMP);
	}
	if (COORD)
	{
		free_coord(COORD);
		free(COORD);
	}
	free(lst);
	free(addr);
	free(image);
}
