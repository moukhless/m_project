/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:59:55 by amoukhle          #+#    #+#             */
/*   Updated: 2022/12/16 15:46:03 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long num)
{
	int	i;
	int	act;

	i = 0;
	act = 0;
	if (num < 0)
	{
		num *= -1;
		act = 1;
		ft_putchar('-');
	}
	if (num >= 10)
		i += ft_putnbr(num / 10);
	i += ft_putchar((char)((num % 10) + '0'));
	return (i + act);
}
