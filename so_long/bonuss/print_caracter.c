/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_caracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:28:21 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/07 22:39:16 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_m(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width_p, var->height_p);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_enemy, var->width_p, var->height_p);
}

void	print_c(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width_p, var->height_p);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_coll, var->width_p, var->height_p);
}

void	print_e(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width_p, var->height_p);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_exit, var->width_p, var->height_p);
}

void	print_p(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_ground, var->width_p, var->height_p);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
		var->img_ptr_player, var->width_p, var->height_p);
}
