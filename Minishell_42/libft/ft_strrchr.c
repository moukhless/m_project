/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:32:54 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/28 18:20:53 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	i = 0;
	c = (unsigned char)c;
	while (str[i] != '\0')
		i++;
	if (c == '\0')
	{
		j = 0;
		while (str[j])
			j++;
		return ((char *)str + j);
	}
	else
	{
		while (i >= 0)
		{
			if (str[i] == c)
				return ((char *)str + i);
			i--;
		}
	}
	return (0);
}
