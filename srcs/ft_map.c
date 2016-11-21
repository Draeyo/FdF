/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 10:16:53 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/05 09:46:59 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		free_split(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

static int		no_color(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

static int		ft_line_len(char *tab)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (tab[i])
	{
		if (ft_isdigit(tab[i]) && (tab[i + 1] && (tab[i + 1] == ' '
						|| tab[i + 1] == '\n' || tab[i + 1] == '\0')))
			++ret;
		i++;
	}
	return (ret);
}

int				**get_coord(t_fdf *lst, char **map)
{
	char	**str;
	int		**ret;
	int		i;
	int		j;

	i = 0;
	ret = (int**)malloc(sizeof(*ret) * LEN_Y);
	LEN_X = 0;
	while (map[i])
	{
		j = 0;
		str = ft_strsplit(map[i], ' ');
		ret[i] = (int*)malloc(sizeof(int) * LINE_LEN);
		while (str[j])
		{
			ret[i][j] = ft_s_atoi(str[j]);
			j++;
		}
		free_split(str);
		i++;
	}
	LEN_X = LINE_LEN;
	return (ret);
}

char			**ft_read(t_fdf *lst, char *file)
{
	int		fd;
	char	**temp;
	int		i;

	i = 0;
	LEN_Y = 0;
	temp = (char**)malloc(sizeof(*temp) * B_SIZE);
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error_fdf(4);
	while (get_next_line(fd, &temp[i]))
	{
		if (temp[0] == '\0')
			exit(EXIT_SUCCESS);
		if (!no_color(temp[i]))
			ft_error_fdf(5);
		if (!LINE_LEN)
			LINE_LEN = ft_line_len(temp[i]);
		LEN_Y++;
		i++;
	}
	temp[i] = NULL;
	close(fd);
	return (temp);
}
