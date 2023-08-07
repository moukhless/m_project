/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:20:01 by hachahbo          #+#    #+#             */
/*   Updated: 2022/10/25 18:17:19 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	d;
	size_t	dorgn;

	if (dstsize == 0 && dst == NULL)
		return (ft_strlen(src));
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	d = ft_strlen(dst);
	dorgn = d;
	c = 0;
	while (src[c] != '\0' && d + 1 < dstsize)
		dst[d++] = src[c++];
	dst[d] = '\0';
	return (dorgn + ft_strlen(src));
}
