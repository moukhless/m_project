/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:50:40 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/22 08:01:14 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_num(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*itoa(int num)
{
	int		count;
	char	*score;
	int		i;

	count = count_num(num);
	i = count - 1;
	score = malloc(count + 1);
	if (!score)
		return (NULL);
	score[count] = '\0';
	while (i >= 0)
	{
		score[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (score);
}

int	get_point(char *str)
{
	int	i;
	int	save;

	i = 0;
	save = 0;
	while (str[i])
	{
		if (str[i] == '.')
			save = i;
		i++;
	}
	return (save);
}
