#include "fdf.h"

int		main(void)
{
//	void	*mlx;
//	void	*win;
	t_pnt	*addr;
	t_map	*map;
	int	x;
	int	y;

	x = 100;
	y = 100;
	addr = (t_pnt*)malloc(sizeof(*addr));
	map = (t_map*)malloc(sizeof(*map));
	addr->mlx = mlx_init();
	addr->win = mlx_new_window(addr->mlx, 400, 400, "FdF");
	mlx_pixel_put(addr->mlx, addr->win, x, y, 0xFFFFFF);
//	mlx_key_hook(win, close_key, 0);
	mlx_loop(addr->mlx);
	free(addr);
	free(map);
	return (0);
}
