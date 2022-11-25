/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:48:54 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/24 14:35:26 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	size_tot;
	void	*p;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	size_tot = count * size;
	p = malloc(size_tot);
	if (!p)
		return (NULL);
	ft_memset(p, 0, size_tot);
	return (p);
}
