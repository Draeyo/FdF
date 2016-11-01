/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 14:05:16 by vlistrat          #+#    #+#             */
/*   Updated: 2016/09/15 15:31:28 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_cutab(char *str, int a, int b)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = (int)ft_strlen(str) - 1;
	while (i < len)
	{
		if (str[i] == a)
			while (str[i] && str[i] != b)
				i++;
		str[j] = str[i];
		i++;
		j++;
	}
	return (str);
}

char	*ft_cuta(char *str, int a)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(str) - 1;
	while (i < len)
	{
		if (str[i] == a)
			while (i < len)
			{
				str[i] = '\0';
				i++;
			}
		i++;
	}
	return (str);
}
