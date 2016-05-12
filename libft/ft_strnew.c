/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:40:18 by vlistrat          #+#    #+#             */
/*   Updated: 2015/11/30 14:08:51 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char*)malloc(sizeof(*ret) * size + 1);
	if (ret == NULL)
		return (NULL);
	while (i <= size)
	{
		ret[i] = '\0';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
