/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:25:50 by amoukhle          #+#    #+#             */
/*   Updated: 2022/10/17 18:26:41 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strcat(char *s1, char *s2, int i )
{
	int	j;

	j = 0;
	while (s2[j])
		s1[i++] = s2[j++];
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p1;
	char	*p2;
	char	*str;
	int		i;

	p1 = (char *)s1;
	p2 = (char *)s2;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = ft_strcat(str, p2, ft_strcat(str, p1, i));
	str[i] = '\0';
	return (str);
}
