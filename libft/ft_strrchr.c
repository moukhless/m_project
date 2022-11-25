/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:05:22 by amoukhle          #+#    #+#             */
/*   Updated: 2022/10/17 21:50:55 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*p1;
	char	*p2;
	int		act;

	act = 0;
	p1 = (char *)str;
	p2 = (char *)str;
	while (*p1)
	{
		if (*p1 == (unsigned char)c)
		{
			p2 = p1;
			act = 1;
		}
		p1++;
	}
	if (act == 1)
		return (p2);
	if (*p1 == (unsigned char)c)
	{
		p2 = p1;
		return (p2);
	}
	return (NULL);
}
