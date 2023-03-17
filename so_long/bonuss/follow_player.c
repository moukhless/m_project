/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:25:20 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/07 22:05:42 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	follow_player_up(t_enemy *enemy, t_var *var)
{
	if (check_all_caracters(enemy->x_enemy, enemy->y_enemy - 1, var) == 1)
	{
		if (check_all_caracters(enemy->x_enemy - 1, enemy->y_enemy, var) == 1)
		{
			if (check_all_caracters(enemy->x_enemy + 1,
					enemy->y_enemy, var) == 1)
				enemy_move_down(enemy, var);
			else
				enemy_move_right(enemy, var);
		}
		else
			enemy_move_left(enemy, var);
	}
	else
		enemy_move_up(enemy, var);
}

void	follow_player_down(t_enemy *enemy, t_var *var)
{
	if (check_all_caracters(enemy->x_enemy, enemy->y_enemy + 1, var) == 1)
	{
		if (check_all_caracters(enemy->x_enemy - 1, enemy->y_enemy, var) == 1)
		{
			if (check_all_caracters(enemy->x_enemy + 1,
					enemy->y_enemy, var) == 1)
				enemy_move_up(enemy, var);
			else
				enemy_move_right(enemy, var);
		}
		else
			enemy_move_left(enemy, var);
	}
	else
		enemy_move_down(enemy, var);
}

void	follow_player_right(t_enemy *enemy, t_var *var)
{
	if (check_all_caracters(enemy->x_enemy + 1, enemy->y_enemy, var) == 1)
	{
		if (check_all_caracters(enemy->x_enemy, enemy->y_enemy - 1, var) == 1)
		{
			if (check_all_caracters(enemy->x_enemy,
					enemy->y_enemy + 1, var) == 1)
				enemy_move_left(enemy, var);
			else
				enemy_move_down(enemy, var);
		}
		else
			enemy_move_up(enemy, var);
	}
	else
		enemy_move_right(enemy, var);
}

void	follow_player_left(t_enemy *enemy, t_var *var)
{
	if (check_all_caracters(enemy->x_enemy - 1, enemy->y_enemy, var) == 1)
	{
		if (check_all_caracters(enemy->x_enemy, enemy->y_enemy - 1, var) == 1)
		{
			if (check_all_caracters(enemy->x_enemy,
					enemy->y_enemy + 1, var) == 1)
				enemy_move_right(enemy, var);
			else
				enemy_move_down(enemy, var);
		}
		else
			enemy_move_up(enemy, var);
	}
	else
		enemy_move_left(enemy, var);
}
