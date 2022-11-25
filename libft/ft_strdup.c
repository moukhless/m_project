/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:30:46 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/24 13:00:43 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*n_str;
	int		i;

	i = 0;
	n_str = (char *)malloc((ft_strlen(src) + 1));
	if (!n_str)
		return (NULL);
	while (src[i])
	{
		n_str[i] = src[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
