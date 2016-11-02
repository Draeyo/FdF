/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 14:00:45 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/02 13:50:34 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char			*ft_put_pixel(t_img *image, t_fdf *lst, int color)
{
	char	*tmp;
	int		var;

	tmp = IMG;
	var = (DRX * (BPP / 8)) + (DRY * SL);
	if (END == 0)
	{
		tmp[var] = color;
		tmp[++var] = color >> 8;
		tmp[++var] = color >> 16;
	}
	else
	{
		tmp[var] = color >> 16;
		tmp[++var] = color >> 8;
		tmp[++var] = color;
	}
	return (IMG);
}

static char		*r_draw_one(t_img *image, t_fdf *lst, int xinc, int yinc)
{
	int		i;
	int		cumul;

	i = 1;
	cumul = DRDX / 2;
	while (i <= DRDX)
	{
		DRX += xinc;
		cumul += DRDY;
		if (cumul >= DRDX)
		{
			cumul -= DRDX;
			DRY += yinc;
		}
		IMG = ft_put_pixel(image, lst, COLOR);
		i++;
	}
	return (IMG);
}

static char		*r_draw_two(t_img *image, t_fdf *lst, int xinc, int yinc)
{
	int		i;
	int		cumul;

	i = 1;
	cumul = DRDY / 2;
	while (i <= DRDY)
	{
		DRY += yinc;
		cumul += DRDX;
		if (cumul >= DRDY)
		{
			cumul -= DRDY;
			DRX += xinc;
		}
		IMG = ft_put_pixel(image, lst, COLOR);
		i++;
	}
	return (IMG);
}

char			*ft_draw(int xf, int yf, t_img *image, t_fdf *lst)
{
	int		xinc;
	int		yinc;

	DRX = X1;
	DRY = Y1;
	DRDX = xf - X1;
	DRDY = yf - Y1;
	xinc = (DRDX > 0) ? 1 : -1;
	yinc = (DRDY > 0) ? 1 : -1;
	DRDX = (DRDX >= 0 ? DRDX : (DRDX * -1));
	DRDY = (DRDY >= 0 ? DRDY : (DRDY * -1));
	IMG = ft_put_pixel(image, lst, COLOR);
	if (DRDX > DRDY)
		IMG = r_draw_one(image, lst, xinc, yinc);
	else
		IMG = r_draw_two(image, lst, xinc, yinc);
	return (IMG);
}

void			ft_put_img(t_fdf *lst, t_img *image, t_pnt *addr)
{
	IMG_P = mlx_new_image(MLX, WIN_X, WIN_Y);
	IMG = mlx_get_data_addr(IMG_P, &BPP, &SL, &END);
	IMG = ft_calc(lst, image, addr);
	mlx_put_image_to_window(MLX, WIN, IMG_P, 0, 0);
	mlx_destroy_image(MLX, IMG_P);
}
