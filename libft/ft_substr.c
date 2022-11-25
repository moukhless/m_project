/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:48:48 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/24 13:05:40 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		j;
	char		*p;
	int			size;

	j = 0;
	if (!s)
		return (NULL);
	p = (char *)s;
	if (len > ft_strlen(p))
		size = ft_strlen(p);
	else
		size = len;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	if (ft_strlen(p) < start)
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	while (p[start] && len-- > 0)
		str[j++] = p[start++];
	str[j] = '\0';
	return (str);
}
