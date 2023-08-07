/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:14:20 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/31 00:21:15 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_overflow(long int prv, long int res)
{
	if (res / 10 != prv)
		return (1);
	return (0);
}

void	ft_sign_space(char *str, int *i, int *sign)
{
	while (str[*i] && (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		*i += 1;
	if (str[*i] && (str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i += 1;
	}
}

unsigned long long int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					sign;
	int					i;
	unsigned long int	prv;

	i = 0;
	res = 0;
	sign = 1;
	ft_sign_space((char *)str, &i, &sign);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		prv = res;
		res = res * 10 + str[i++] - '0';
		if (is_overflow(prv, res) == 1)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
	}
	return (res * sign);
}
