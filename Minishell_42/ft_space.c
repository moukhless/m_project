/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:21:24 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/31 21:38:28 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_spaces(char *str)
{
	if (!ft_strcmp(str, " ") || !ft_strcmp(str, "\n")
		|| !ft_strcmp(str, "\t"))
		return (1);
	return (0);
}

int	ft_strisspace(const char *str)
{
	while (*str)
	{
		if (!isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

char	*skip_spaces(char *input)
{
	int	i;

	i = 0;
	while ((input[i] >= 9 && input[i] <= 13) || input[i] == 32)
		i++;
	return (input + i);
}
