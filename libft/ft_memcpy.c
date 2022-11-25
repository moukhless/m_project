/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:02:04 by amoukhle          #+#    #+#             */
/*   Updated: 2022/10/20 13:39:29 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char	*dst;
	char	*str;
	size_t	counter;

	if (!destination && !source)
		return (NULL);
	dst = (char *)destination;
	str = (char *)source;
	counter = 0;
	while (counter < size)
	{
		*(dst + counter) = *(str + counter);
		counter++;
	}
	return (dst);
}
