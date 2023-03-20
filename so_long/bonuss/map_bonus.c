/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:02:49 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 01:36:27 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_bonus(t_var *var)
{
	int	i;
	int	j;

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

void	map_next_bonus(t_var *var, int i, int j)
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
	else
		map_next_bonus1(var, i, j);
}

void	map_next_bonus1(t_var *var, int i, int j)
{
	if (var->str[j][i] == 'P')
	{
		var->x = i;
		var->y = j;
		print_p(var);
	}
	else if (var->str[j][i] == 'M')
	{
		addenemy(&(var->enemy), new_enemy(i, j));
		print_m(var);
	}
	else
	{
		write(2, "ERROR\n", 6);
		write(2, "there are a caracter not defined.\n", 34);
		free_all_and_exit_bonus(var);
	}
}
