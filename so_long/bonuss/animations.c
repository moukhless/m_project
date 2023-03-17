/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:25:53 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/17 12:38:17 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation_of_coll_next(t_var *var, int *count)
{
	int	width_img;
	int	height_img;

	if (*count == 35)
		var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
				"textures/collectible5.xpm", &width_img, &height_img);
	if (*count == 42)
		var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
				"textures/collectible6.xpm", &width_img, &height_img);
	if (*count == 49)
		var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
				"textures/collectible7.xpm", &width_img, &height_img);
	if (*count == 56)
		var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
				"textures/collectible8.xpm", &width_img, &height_img);
	if (*count == 63)
	{
		var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
				"textures/collectible4.xpm", &width_img, &height_img);
		*count = 0;
	}
}

void	animation_of_coll(t_var *var, int *count)
{
	int	width_img;
	int	height_img;

	if (*count == 7)
		var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
				"textures/collectible1.xpm", &width_img, &height_img);
	if (*count == 14)
		var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
				"textures/collectible2.xpm", &width_img, &height_img);
	if (*count == 21)
		var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
				"textures/collectible3.xpm", &width_img, &height_img);
	if (*count == 28)
		var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
				"textures/collectible4.xpm", &width_img, &height_img);
	animation_of_coll_next(var, count);
	protect_img_bonus(var);
}

void	animation_of_exit(t_var *var, int *count_exit)
{
	int	width_img;
	int	height_img;

	if (var->number_of_coll == 0)
	{
		(*count_exit)++;
		if (*count_exit == 15)
			var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr,
					"textures/exit.xpm", &width_img, &height_img);
		if (*count_exit == 30)
			var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr,
					"textures/exit1.xpm", &width_img, &height_img);
		if (*count_exit == 45)
			var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr,
					"textures/exit2.xpm", &width_img, &height_img);
		if (*count_exit == 60)
			var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr,
					"textures/exit3.xpm", &width_img, &height_img);
	}
	protect_img_bonus(var);
}

void	animation_of_coll_and_exit(t_var *var, int *count_coll, int *count_exit)
{
	animation_of_coll(var, count_coll);
	animation_of_exit(var, count_exit);
}

void	animation_of_enemy(t_var *var, int *count_e)
{
	t_enemy	*p;

	p = var->enemy;
	if (*count_e == 40)
	{
		while (p)
		{
			enemy_movement(p, var);
			protect_img_bonus(var);
			p = p->next;
		}
		*count_e = 0;
	}
}
