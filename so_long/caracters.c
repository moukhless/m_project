/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caracters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:31:12 by amoukhle          #+#    #+#             */
/*   Updated: 2023/02/23 22:46:36 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_a_wall(int width, int height, t_var *var)
{
	int	x;
	int	y;

	x = width / 60;
	y = height / 60;
	if (var->str[y][x] == '1')
		return (1);
	return (0);
}

int is_a_collectible(int width, int height, t_var *var)
{
	int	x;
	int	y;

	x = width / 60;
	y = height / 60;
	if (var->str[y][x] == 'C')
	{
		var->str[y][x] = '0';
		return (1);
	}
	return (0);
}

int is_a_exit(int width, int height, t_var *var)
{
	int	x;
	int	y;

	x = width / 60;
	y = height / 60;
	if (var->str[y][x] == 'E')
		return (1);
	return (0);
}