#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_map
{
	int	x;
	int	y;
	int	*value;
}		t_map;

typedef struct	s_pnt
{
	void	*mlx;
	void	*win;
}		t_pnt;

/* close_key.c */
int	close_key(int keycode, void *param);

#endif
