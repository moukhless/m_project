/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:19:17 by hachahbo          #+#    #+#             */
/*   Updated: 2022/10/21 12:05:43 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;

	if (!s1 || !set)
		return (0);
	str = (char *)s1;
	i = 0;
	while (*str != '\0' && ft_strchr(set, *str))
		str++;
	i = ft_strlen(str);
	while (i != 0 && ft_strchr(set, str[i]))
		i--;
	return (ft_substr(str, 0, i + 1));
}
