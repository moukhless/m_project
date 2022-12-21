/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:29:41 by amoukhle          #+#    #+#             */
/*   Updated: 2022/12/16 15:46:28 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i = ft_putstr("(null)");
	else
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}
