/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:31:15 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/07 22:39:04 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_up_bonus(t_var *var)
{
	if (is_a_collectible_bonus(var->x, var->y, var) == 1)
		var->number_of_coll--;
	if (is_a_exit_bonus(var->x, var->y, var) == 1 && var->number_of_coll == 0)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You won!\n", 9);
		free_all_and_exit_bonus(var);
	}
	if (is_a_enemy_bonus(var->x, var->y, var) == 1)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You lose!\n", 10);
		free_all_and_exit_bonus(var);
	}
	var->str[var->y][var->x] = 'P';
	var->str[var->y + 1][var->x] = '0';
	return (0);
}

int	move_down_bonus(t_var *var)
{
	if (is_a_collectible_bonus(var->x, var->y, var) == 1)
		var->number_of_coll--;
	if (is_a_exit_bonus(var->x, var->y, var) == 1 && var->number_of_coll == 0)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You won!\n", 9);
		free_all_and_exit_bonus(var);
	}
	if (is_a_enemy_bonus(var->x, var->y, var) == 1)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You lose!\n", 10);
		free_all_and_exit_bonus(var);
	}
	var->str[var->y][var->x] = 'P';
	var->str[var->y - 1][var->x] = '0';
	return (0);
}

int	move_right_bonus(t_var *var)
{
	if (is_a_collectible_bonus(var->x, var->y, var) == 1)
		var->number_of_coll--;
	if (is_a_exit_bonus(var->x, var->y, var) == 1 && var->number_of_coll == 0)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You won!\n", 9);
		free_all_and_exit_bonus(var);
	}
	if (is_a_enemy_bonus(var->x, var->y, var) == 1)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You lose!\n", 10);
		free_all_and_exit_bonus(var);
	}
	var->str[var->y][var->x] = 'P';
	var->str[var->y][var->x - 1] = '0';
	return (0);
}

int	move_left_bonus(t_var *var)
{
	if (is_a_collectible_bonus(var->x, var->y, var) == 1)
		var->number_of_coll--;
	if (is_a_exit_bonus(var->x, var->y, var) == 1 && var->number_of_coll == 0)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You won!\n", 9);
		free_all_and_exit_bonus(var);
	}
	if (is_a_enemy_bonus(var->x, var->y, var) == 1)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You lose!\n", 10);
		free_all_and_exit_bonus(var);
	}
	var->str[var->y][var->x] = 'P';
	var->str[var->y][var->x + 1] = '0';
	return (0);
}
