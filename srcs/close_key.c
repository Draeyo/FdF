/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 11:36:50 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/02 13:52:46 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_key(int keycode, void *param)
{
	t_fdf	*lst;

	lst = (t_fdf*)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode >= 18 && keycode <= 23)
	{
		if (keycode == 18)
			COLOR = RED;
		else if (keycode == 19)
			COLOR = GREEN;
		else if (keycode == 20)
			COLOR = BLUE;
		else if (keycode == 21)
			COLOR = WHITE;
		else if (keycode == 23 && COLOR > 0xF)
			COLOR -= 0xF;
		else if (keycode == 26 && COLOR < 0xFFFFF0 )
			COLOR += 0xF;
		struct_init(lst, lst->image, lst->addr);
		recalc_xy(lst);
		ft_put_img(lst, lst->image, lst->addr);
	}
	else
		ft_printf("%d\n", keycode);
	return (0);
}
