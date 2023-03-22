/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:29:49 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/21 11:20:06 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map(t_var *var)
{
	int	i;
	int	j;

	j = 0;
	var->height_p = 0;
	while (var->height_p < var->height_win)
	{
		i = 0;
		var->width_p = 0;
		while (var->width_p < var->width_win)
		{
			map_next(var, i, j);
			var->width_p += 60;
			i++;
		}
		j++;
		var->height_p += 60;
	}
}

void	map_next(t_var *var, int i, int j)
{
	if (var->str[j][i] == '1')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img_ptr_wall, var->width_p, var->height_p);
	else if (var->str[j][i] == '0')
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr,
			var->img_ptr_ground, var->width_p, var->height_p);
	else if (var->str[j][i] == 'C')
		print_c(var);
	else if (var->str[j][i] == 'E')
		print_e(var);
	else if (var->str[j][i] == 'P')
	{
		var->width = var->width_p;
		var->height = var->height_p;
		print_p(var);
	}
	else
	{
		write(2, "ERROR\n", 6);
		write(2, "there are a caracter not defined.\n", 34);
		free_all_and_exit(var);
	}
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
