/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:07:44 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/02 14:22:38 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		calc_ver(t_fdf *lst, t_img *image, int tmp)
{
	UPY = tmp;
	if (ALT == UPY)
		Y3 = Y1 + DY;
	else if (UPY == 0)
		Y3 = ZALT + DY;
	else
		Y3 = (ZALT - (DY * (UPY * 3))) + (DY * 2) - tmp;
	IMG = ft_draw(X2, Y3, image, lst);
}

static void		calc_hor(t_fdf *lst, t_img *image, int tmp)
{
	UPY = tmp;
	Y2 = (ZALT - (DY * (UPY ? (UPY * 3) : 1))) - tmp;
	X2 = X1 + DX;
	if (X2 <= LX)
		IMG = ft_draw(X2, Y2, image, lst);
}

static void		reduce_while(t_fdf *lst, t_img *image, int i, int **tmp)
{
	int		j;

	while (FDF_Y < LY)
	{
		j = 0;
		X1 = FDF_X;
		Y1 = FDF_Y - (tmp[i][j] * DY * 3) - tmp[i][j];
		ZALT = FDF_Y;
		while (X2 <= LX)
		{
			if ((ALT = tmp[i][j]))
				ALT *= 3;
			calc_hor(lst, image, tmp[i][j + 1]);
			if (i + 1 < LEN_Y)
				calc_ver(lst, image, tmp[i + 1][j]);
			X1 += DX;
			Y1 = Y2;
			ZALT -= DY;
			j++;
		}
		i++;
		FDF_Y += DY;
		FDF_X += DX;
		LX += DX;
	}
}

char			*ft_calc(t_fdf *lst, t_img *image, t_pnt *addr)
{
	int		**tmp;
	int		i;
	int		j;

	tmp = COORD;
	FDF_X = ((WIN_X / 2) - (((LEN_X * DX) / 2) + ((LEN_Y * DX) / 2)));
	FDF_Y = (WIN_Y - (LEN_Y * DY));
	LY = (LEN_Y * DY) + FDF_Y;
	LX = (LEN_X * DX) + FDF_X;
	i = 0;
	reduce_while(lst, image, i, tmp);
	return (IMG);
}
