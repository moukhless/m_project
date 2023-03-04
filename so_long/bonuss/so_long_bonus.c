/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:22:31 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/04 02:46:01 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void affiche_map(t_var *var)
{
	int i;
	int j;

	i = 0;
	while (var->str[i])
	{
		j = 0;
		while (var->str[i][j])
		{
			printf("%c", var->str[i][j]);
			j++;
		}
		i++;
	}
	
}

int drawing_map(t_var *var)
{	static int count;
	static int count_e;
	static int count_exit;
	int width_img;
	int height_img;

	count++;
	count_e++;
	
	protect_img_bonus(var);
	animation_of_coll(var ,&count);
	map_bonus(var);
	if (count_e == 20)
	{
		enemy_movement(var);
		count_e = 0;
	}
	if (var->number_of_coll == 0)
	{
		count_exit++;
		if (count_exit == 15)
			var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr, "textures/exit.xpm", &width_img, &height_img);
		if (count_exit == 30)
			var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr, "textures/exit1.xpm", &width_img, &height_img);
		if (count_exit == 45)
			var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr, "textures/exit2.xpm", &width_img, &height_img);
		if (count_exit == 60)
			var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr, "textures/exit3.xpm", &width_img, &height_img);
	}
	mlx_hook(var->win_ptr, 2, 0, &handle_key_press_bonus, var);
	return (0);
}

int main(int argc, char **argv)
{
    t_var *var;
    int width_img;
	int height_img;
	int fd;
	
	fd = open(argv[argc - 1], O_RDWR);
	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		return (0);
	fill_map_in_matrix_bonus(var, fd, argv);
	var->mlx_ptr = mlx_init();
	var->win_ptr = mlx_new_window(var->mlx_ptr, var->width_win, var->height_win, "My Window");
   	var->img_ptr_wall = mlx_xpm_file_to_image(var->mlx_ptr, "textures/wall.xpm", &width_img, &height_img);
	var->img_ptr_ground = mlx_xpm_file_to_image(var->mlx_ptr, "textures/ground.xpm", &width_img, &height_img);
	var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible.xpm", &width_img, &height_img);
	var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr, "textures/exit.xpm", &width_img, &height_img);
	var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr, "textures/enemy_up.xpm", &width_img, &height_img);
	var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr, "textures/player_right1.xpm", &width_img, &height_img);

	mlx_loop_hook(var->mlx_ptr, &drawing_map, var);
	mlx_hook(var->win_ptr, 17, 0, &destroy_notify_handler, var);
    mlx_loop(var->mlx_ptr);
	return(0);
}
