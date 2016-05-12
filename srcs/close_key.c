#include "fdf.h"

int		close_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(42);
	return (0);
}
