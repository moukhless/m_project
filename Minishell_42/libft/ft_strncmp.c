/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:10:33 by hachahbo          #+#    #+#             */
/*   Updated: 2022/10/17 18:40:18 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (c1[i] == c2[i] && i < n - 1 && c1[i] != 0 && c2[i] != 0)
		i++;
	return (c1[i] - c2[i]);
}
