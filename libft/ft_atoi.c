/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:21:02 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/24 12:44:04 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					c;
	int					s;
	unsigned long long	res;

	c = 0;
	s = 1;
	res = 0;
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n'
		|| str[c] == '\v' || str[c] == '\f' || str[c] == '\r')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c++] == '-')
			s = -1;
	}
	while (ft_isdigit(str[c]) == 1)
	{
		res = (res * 10) + (str[c] - '0');
		c++;
	}
	if (res > 9223372036854775807 && s == -1)
		return (0);
	if (res > 9223372036854775806)
		return (-1);
	return (res * s);
}
