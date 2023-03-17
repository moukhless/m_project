/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:29:10 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/07 20:27:05 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width, var->height);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_player, var->width, var->height);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width, var->height + 60);
	return (0);
}

int	move_down(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width, var->height);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_player, var->width, var->height);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width, var->height - 60);
	return (0);
}

int	move_right(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width, var->height);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_player, var->width, var->height);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width - 60, var->height);
	return (0);
}

int	move_left(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width, var->height);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_player, var->width, var->height);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width + 60, var->height);
	return (0);
}
