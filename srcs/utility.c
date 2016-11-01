/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:29:10 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/01 09:27:17 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_len_x(char **map)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (map[0][i])
	{
		if (ft_isdigit(map[0][i]))
			ret++;
		i++;
	}
	return (ret);
}

void	struct_init(t_fdf *lst, t_img *image, t_pnt *addr)
{
	LEN_X = 0;
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
	COLOR = WHITE;
}

int		ft_error_fdf(int e)
{
	if (e == 1)
		ft_putendl_fd("Map size is too high.", 2);
	else if (e == 4)
		ft_putendl_fd("Invalid file descriptor.", 2);
	exit(EXIT_FAILURE);
	return (0);
}

int		mlx_data(t_pnt *addr, t_img *image)
{
	if (!(MLX = mlx_init()))
		return (ft_error_fdf(1));
	if (!(WIN = mlx_new_window(MLX, WIN_X, WIN_Y, "FdF")))
		return (ft_error_fdf(2));
	if (!(IMG_P = mlx_new_image(MLX, WIN_X, WIN_Y)))
		return (ft_error_fdf(3));
	return (1);
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
