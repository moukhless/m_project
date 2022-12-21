/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:38:12 by amoukhle          #+#    #+#             */
/*   Updated: 2022/12/16 15:45:28 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int num, char ch)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (ch == 'X')
		str = "0123456789ABCDEF";
	if (num >= 16)
		i += ft_puthex(num / 16, ch);
	i += ft_putchar(str[num % 16]);
	return (i);
}
