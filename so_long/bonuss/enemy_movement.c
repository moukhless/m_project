/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:22:43 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/21 11:12:56 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_movement(t_enemy *enemy, t_var *var)
{
	if (var->y < enemy->y_enemy)
		follow_player_up(enemy, var);
	else if (var->y > enemy->y_enemy)
		follow_player_down(enemy, var);
	else if (var->x > enemy->x_enemy)
		follow_player_right(enemy, var);
	else if (var->x < enemy->x_enemy)
		follow_player_left(enemy, var);
}

void	enemy_move_up(t_enemy *enemy, t_var *var)
{
	int	width_img;
	int	height_img;

	enemy->y_enemy -= 1;
	var->str[enemy->y_enemy][enemy->x_enemy] = 'M';
	var->str[enemy->y_enemy + 1][enemy->x_enemy] = '0';
	var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/enemy_up.xpm", &width_img, &height_img);
	if (var->x == enemy->x_enemy && var->y == enemy->y_enemy)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You lose!\n", 10);
		t_enemy_clean(&(var->enemy));
		free_all_and_exit_bonus(var);
	}
}

void	enemy_move_down(t_enemy *enemy, t_var *var)
{
	int	width_img;
	int	height_img;

	enemy->y_enemy += 1;
	var->str[enemy->y_enemy][enemy->x_enemy] = 'M';
	var->str[enemy->y_enemy - 1][enemy->x_enemy] = '0';
	var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/enemy_down.xpm", &width_img, &height_img);
	if (var->x == enemy->x_enemy && var->y == enemy->y_enemy)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You lose!\n", 10);
		t_enemy_clean(&(var->enemy));
		free_all_and_exit_bonus(var);
	}
}

void	enemy_move_right(t_enemy *enemy, t_var *var)
{
	int	width_img;
	int	height_img;

	enemy->x_enemy += 1;
	var->str[enemy->y_enemy][enemy->x_enemy] = 'M';
	var->str[enemy->y_enemy][enemy->x_enemy - 1] = '0';
	var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/enemy_right.xpm", &width_img, &height_img);
	if (var->x == enemy->x_enemy && var->y == enemy->y_enemy)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You lose!\n", 10);
		t_enemy_clean(&(var->enemy));
		free_all_and_exit_bonus(var);
	}
}

void	enemy_move_left(t_enemy *enemy, t_var *var)
{
	int	width_img;
	int	height_img;

	enemy->x_enemy -= 1;
	var->str[enemy->y_enemy][enemy->x_enemy] = 'M';
	var->str[enemy->y_enemy][enemy->x_enemy + 1] = '0';
	var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/enemy_left.xpm", &width_img, &height_img);
	if (var->x == enemy->x_enemy && var->y == enemy->y_enemy)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		write(1, "You lose!\n", 10);
		t_enemy_clean(&(var->enemy));
		free_all_and_exit_bonus(var);
	}
}
