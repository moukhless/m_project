/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:40:09 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/27 23:40:55 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_data(char *input, int *start, int *end)
{
	char	*str;
	char	*c;
	int		temp;

	temp = *end;
	c = (input + *end);
	if (ft_strcmp(c, "\0") == 0)
		return (0);
	while ((input[*end] >= 'a' && input[*end] <= 'z') || 
		(input[*end] >= 'A' && input[*end] <= 'Z') 
		|| (input[*end] >= '0' && input[*end] <= '9') || input[*end] == '_')
		*end += 1;
	if (temp == *end)
	{
		if ((input[*end] == '>' && input[*end + 1] == '>') 
			|| (input[*end] == '<' && input[*end + 1] == '<'))
			*end += 1;
		*end += 1;
		str = ft_substr(input, *start, *end - *start);
		*start = *end;
		return (str);
	}
	str = ft_substr(input, *start, *end - *start);
	*start = *end;
	return (str);
}
