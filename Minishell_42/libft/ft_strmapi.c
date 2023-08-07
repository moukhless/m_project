/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:40:11 by hachahbo          #+#    #+#             */
/*   Updated: 2022/10/17 18:39:50 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*d;
	size_t	l;

	if (!s || !f)
		return (0);
	l = ft_strlen(s);
	d = (char *)malloc(l + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < l)
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
