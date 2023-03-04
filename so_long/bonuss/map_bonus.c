/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:02:49 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/04 00:25:22 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long_bonus.h"

void map_bonus(t_var *var)
{
	int i;
	int j;

	j = 0;
	var->height_p = 0;
	while (var->str[j])
	{
		i = 0;
		var->width_p = 0;
		while (var->str[j][i] != '\n')
		{
			map_next_bonus(var, i, j);
			var->width_p += 60;
			i++;
		}
		j++;
		var->height_p += 60;
	}
}

void map_next_bonus(t_var *var, int i, int j)
{
	if (var->str[j][i] == '1')
    	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_wall, var->width_p, var->height_p);
	else if (var->str[j][i] == '0')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_ground, var->width_p, var->height_p);
	else if (var->str[j][i] == 'C')
		print_C(var);
	else if (var->str[j][i] == 'E')
		print_E(var);
	else if (var->str[j][i] == 'P')
	{
		var->x = i;
		var->y = j;
		print_P(var);
	}
	else if (var->str[j][i] == 'M')
	{
		var->x_enemy = i;
		var->y_enemy = j;
		print_M(var);
	}
	else
	{
		write(2, "there are a caracter not defined.\n", 34);
		free_all_and_exit_bonus(var);
	}
}

void print_M(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_ground, var->width_p, var->height_p);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_enemy, var->width_p, var->height_p);
}

void print_C(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_ground, var->width_p, var->height_p);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_coll, var->width_p, var->height_p);
}

void print_E(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_ground, var->width_p, var->height_p);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_exit, var->width_p, var->height_p);
}

void print_P(t_var *var)
{
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_ground, var->width_p, var->height_p);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr_player, var->width_p, var->height_p);
}