/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:25:50 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/31 16:20:12 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 420

typedef struct			s_lig
{
	int			c_read;
	int			fd;
	int			j;
	char		mess[409600];
	struct s_lig	*next;
	struct s_lig	*first;
}						t_lig;

int						get_next_line(int const fd, char **line);

#endif
