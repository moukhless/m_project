/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caracters_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:14:55 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/04 02:18:54 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int is_a_wall_bonus(int x, int y, t_var *var)
{
	if (var->str[y][x] == '1')
		return (1);
	return (0);
}

int is_a_collectible_bonus(int x, int y, t_var *var)
{
	if (var->str[y][x] == 'C')
		return (1);
	return (0);
}

int is_a_exit_bonus(int x, int y, t_var *var)
{
	if (var->str[y][x] == 'E')
		return (1);
	return (0);
}

int is_a_enemy_bonus(int x, int y, t_var *var)
{
	if (var->str[y][x] == 'M')
		return (1);
	return (0);
}