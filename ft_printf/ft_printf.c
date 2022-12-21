/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:28:44 by amoukhle          #+#    #+#             */
/*   Updated: 2022/11/27 23:09:20 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_address(unsigned long num)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	if (num == 0)
		count += ft_putchar('0');
	else
		count += ft_puthex_adr(num);
	return (count);
}

int	print(va_list list, char ch)
{
	int	count;

	count = 0;
	if (ch == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (ch == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (ch == 'p')
		count += ft_put_address(va_arg(list, unsigned long));
	else if (ch == 'd' || ch == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (ch == 'u')
		count += ft_putnbr(va_arg(list, unsigned int));
	else if (ch == 'x' || ch == 'X')
		count += ft_puthex(va_arg(list, unsigned int), ch);
	else if (ch == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;
	int		count;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{	
			i++;
			count += print(list, str[i]);
			if (str[i] == '\0')
				i--;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}
