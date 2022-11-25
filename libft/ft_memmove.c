/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 07:47:24 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/24 12:03:28 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	if (dest <= src)
		ft_memcpy(dest, src, size);
	else
	{
		while (size > 0)
		{
			*((char *)(dest + size - 1)) = *((char *)(src + size - 1));
			size--;
		}
	}
	return (dest);
}
