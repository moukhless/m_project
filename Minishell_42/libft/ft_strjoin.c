/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:04:36 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/28 18:21:22 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_extralen(char const *s1, char const *s2)
{
	size_t	extralen;

	if (!s1)
		extralen = ft_strlen((char *)s2);
	else if (!s2)
		extralen = ft_strlen((char *)s1);
	else
		extralen = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	return (extralen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	extralen;
	char	*str;

	if (s1 == 0 && s2 == 0)
		return (0);
	extralen = count_extralen(s1, s2);
	str = (char *)malloc(extralen + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
