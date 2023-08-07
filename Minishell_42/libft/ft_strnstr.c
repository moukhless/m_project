/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:22:53 by hachahbo          #+#    #+#             */
/*   Updated: 2022/10/23 18:59:49 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*to_find)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] != '\0' && to_find[j] && i + j < len \
			&& haystack[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
