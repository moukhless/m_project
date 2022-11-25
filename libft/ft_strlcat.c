/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:49:32 by amoukhle          #+#    #+#             */
/*   Updated: 2022/10/19 21:29:44 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		i;
	size_t	len_dest;
	size_t	len_dest1;

	i = 0;
	if (!dest && size == 0)
		return (0);
	if (ft_strlen(dest) >= size)
		return (size + ft_strlen(src));
	else
	{
		len_dest1 = ft_strlen(dest);
		len_dest = ft_strlen(dest);
		while (src[i] && len_dest < size - 1)
		{
			dest[len_dest] = src[i];
			len_dest++;
			i++;
		}
		dest[len_dest] = '\0';
		return (len_dest1 + ft_strlen(src));
	}
}
