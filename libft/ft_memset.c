/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:03:26 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/24 11:14:41 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			counter;
	unsigned char	*str;

	str = (unsigned char *) pointer;
	counter = 0;
	while (counter < count)
	{
		*str = (unsigned char) value;
		str++;
		counter++;
	}
	return (pointer);
}
