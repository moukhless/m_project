/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_adr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:41:04 by amoukhle          #+#    #+#             */
/*   Updated: 2022/12/16 15:45:41 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex_adr(unsigned long num)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (num >= 16)
		i += ft_puthex_adr(num / 16);
	i += ft_putchar(str[num % 16]);
	return (i);
}
