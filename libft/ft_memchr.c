/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:54:50 by amoukhle          #+#    #+#             */
/*   Updated: 2022/10/21 09:45:00 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	if (!n)
		return (NULL);
	p = (unsigned char *)str;
	while (i < n)
	{
		if (*(p + i) == (unsigned char)c)
			return (p + i);
		i++;
	}
	return (NULL);
}
