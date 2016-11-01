/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 09:32:37 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/01 09:27:51 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define A_SIZE 4096
# define B_SIZE 2048

# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define WHITE 0xFFFFFF

# define MAP lst->map
# define COORD lst->coord
# define TMP lst->tmp
# define LEN_X lst->len_x
# define LEN_Y lst->len_y
# define ALT lst->alt
# define COLOR lst->color
# define LX lst->lx
# define LY lst->ly
# define VALT lst->val_alt
# define DX lst->dx
# define DY lst->dy
# define UPY lst->upy
# define X1 lst->x1
# define X2 lst->x2
# define Y1 lst->y1
# define Y2 lst->y2
# define Y3 lst->y3
# define ZALT lst->zalt
# define LENMAX lst->lenmax
# define FDF_X lst->fdf_x
# define FDF_Y lst->fdf_y
# define DRDX lst->draw_dx
# define DRDY lst->draw_dy
# define DRX lst->draw_x
# define DRY lst->draw_y
# define LINE_LEN lst->line_len

# define MLX addr->mlx
# define WIN addr->win
# define WIN_X addr->win_x
# define WIN_Y addr->win_y

# define X map->x
# define Y map->y
# define Z map->z
# define MNEXT map->next

# define IMG image->img
# define IMG_P image->img_ptr
# define BPP image->bpp
# define END image->endian
# define SL image->s_line

typedef struct		s_fdf
{
	char			**map;
	int				**coord;
	char			**tmp;
	int				len_x;
	int				len_y;
	int				alt;
	int				color;
	int				lx;
	int				ly;
	int				val_alt;
	int				dx;
	int				dy;
	int				upy;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				y3;
	int				zalt;
	int				lenmax;
	int				fdf_x;
	int				fdf_y;
	int				draw_dx;
	int				draw_dy;
	int				draw_x;
	int				draw_y;
	struct s_pnt	*addr;
	struct s_img	*image;
	int				line_len;
}					t_fdf;

typedef struct		s_pnt
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
}					t_pnt;

typedef struct		s_img
{
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				s_line;
	int				endian;
}					t_img;

/*
** Mise en place
*/
int					**get_coord(t_fdf *lst, char **map);
char				**ft_read(t_fdf *lst, char *file);

/*
** Utilitaires
*/
int					ft_len_x(char **map);
void				struct_init(t_fdf *lst, t_img *image, t_pnt *addr);

int					close_key(int keycode, void *param);
int					ft_error_fdf(int e);
int					mlx_data(t_pnt *addr, t_img *image);
int					calc_len_max(t_fdf *lst);

char				*ft_cutab(char *str, int a, int b);
char				*ft_cuta(char *str, int a);
/*
**	Allocation / free
*/
void				ft_free_listes(t_fdf *lst, t_pnt *addr, t_img *images);

/*
** Draw
*/
char				*ft_put_pixel(t_img *image, t_fdf *lst, int color);
char				*ft_draw(int xf, int yf, t_img *image, t_fdf *lst);
char				*ft_calc(t_fdf *lst, t_img *image, t_pnt *addr);

void				ft_put_img(t_fdf *lst, t_img *image, t_pnt *addr);

#endif
