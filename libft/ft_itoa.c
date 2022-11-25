/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:07:32 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/24 13:50:10 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size_str(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += 1;
		n *= -1;
	}
	while (n >= 10)
	{
		count += 1;
		n /= 10;
	}
	return (count + 1);
}

static char	*fill_str(char *str, long n)
{
	int	j;

	j = count_size_str(n);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[j--] = '\0';
	while (n >= 10)
	{
		str[j--] = (n % 10) + '0';
		n /= 10;
	}
	str[j] = n + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(count_size_str(n) + 1);
	if (!str)
		return (NULL);
	return (fill_str(str, n));
}
