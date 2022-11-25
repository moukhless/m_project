/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:31:30 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/24 13:10:34 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen((char *)s1);
	while ((char)s1[i] && chr((char *)set, (char)s1[i]))
		i++;
	while (j > i && chr((char *)set, (char)s1[j - 1]))
		j--;
	str = (char *)malloc(j - i + 1);
	if (!str)
		return (NULL);
	while (i < j)
		str[k++] = (char)s1[i++];
	str[k] = '\0';
	return (str);
}
