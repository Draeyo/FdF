/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 09:31:22 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/02 14:23:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		recalc_xy(t_fdf *lst)
{
	int		testx;
	int		testy;

	testx = (((LEN_X * DX) + (LEN_Y * DX)) * 1.5);
	testy = (((LEN_Y * DY) + (LEN_X * DY) + ((LENMAX * 3) * DY) + LENMAX));
	if (testx > 1800 || testy > 1012)
	{
		while (testx > 1800 || testy > 1012)
		{
			if (DX == 2 && DY == 1 && (testx > 1800 || testy > 1012))
				ft_error_fdf(1);
			if (DX > 2 && testx > 1800)
				DX--;
			if (DY > 1 && testy > 1012)
				DY--;
			testx = (((LEN_X * DX) + (LEN_Y * DX)) * 1.5);
			testy = (((LEN_Y * DY) + (LEN_X * DY) + ((LENMAX * 3) * DY) + LENMAX));
		}
	}
}

int				main(int ac, char **av)
{
	int		fd;
	t_fdf	*lst;
	t_pnt	*addr;
	t_img	*image;

	fd = 0;
	if (ac != 2)
		return (0);
	//ft_printf("\x1b[1;32mFDF INITIALIZED...\x1b[0m\n");
	addr = (t_pnt*)malloc(sizeof(*addr));
	lst = (t_fdf*)malloc(sizeof(*lst));
	image = (t_img*)malloc(sizeof(*image));
	MLX = mlx_init();
	struct_init(lst, image, addr);
	COLOR = WHITE;
	MAP = ft_read(lst, av[1]);
	COORD = get_coord(lst, MAP);
	LENMAX = calc_len_max(lst);
	recalc_xy(lst);
	WIN_X = (((LEN_X * DX) + (LEN_Y * DX)) * 1.5);
	WIN_Y = (((LEN_Y * DY) + (LEN_X * DY) + ((LENMAX * 3) * DY) + LENMAX));
	WIN = mlx_new_window(MLX, WIN_X, WIN_Y, "FdF");
	lst->addr = addr;
	lst->image = image;
	ft_put_img(lst, image, addr);
	mlx_key_hook(WIN, close_key, lst);
	mlx_loop(MLX);
	ft_free_listes(lst, addr, image);
	return (0);
}
