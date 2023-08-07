/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:13:54 by hachahbo          #+#    #+#             */
/*   Updated: 2022/10/25 15:58:40 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	totsize;

	if ((SIZE_MAX <= count || SIZE_MAX <= size) \
		|| count * size >= SIZE_MAX)
		return (NULL);
	totsize = count * size;
	str = malloc(totsize);
	if (!str)
		return (0);
	ft_memset(str, 0, totsize);
	return (str);
}
