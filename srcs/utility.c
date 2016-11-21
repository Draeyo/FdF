/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:29:10 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/05 09:46:43 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	struct_init(t_fdf *lst, t_img *image, t_pnt *addr)
{
	if (!LEN_X)
		LEN_X = 0;
	if (!LEN_Y)
		LEN_Y = 0;
	IMG = NULL;
	BPP = 0;
	SL = 0;
	ALT = 0;
	X2 = 0;
	Y2 = 0;
	Y3 = 0;
	UPY = 0;
	FDF_X = 0;
	FDF_Y = 0;
	DRX = 0;
	DRY = 0;
	DRDX = 0;
	DRDY = 0;
	DX = 15;
	DY = 7;
	LINE_LEN = 0;
	lst->addr = addr;
	lst->image = image;
}

int		ft_error_fdf(int e)
{
	if (e == 1)
		ft_putendl_fd("Map size is too high.", 2);
	else if (e == 4)
		ft_putendl_fd("Invalid file descriptor.", 2);
	else if (e == 5)
		ft_putendl_fd("Invalid symbols.", 2);
	exit(EXIT_SUCCESS);
	return (0);
}

int		calc_len_max(t_fdf *lst)
{
	int		**tmp;
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	tmp = COORD;
	while (i < LEN_Y)
	{
		j = 0;
		while (j < LEN_X)
		{
			if (tmp[i][j] > ret)
				ret = tmp[i][j];
			j++;
		}
		i++;
	}
	return (ret);
}
