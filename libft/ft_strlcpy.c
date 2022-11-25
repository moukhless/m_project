/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:08:57 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/24 12:04:25 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	int		length;

	length = ft_strlen(src);
	counter = 0;
	if (dstsize == 0)
		return (length);
	while (*src && counter < dstsize - 1)
	{
		*dst++ = *src++;
		counter++;
	}
	*dst = '\0';
	return (length);
}
