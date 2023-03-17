/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:27:08 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/17 12:43:09 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialisation(t_var *var)
{
	int	width_img;
	int	height_img;

	var->mlx_ptr = mlx_init();
	var->win_ptr = mlx_new_window(var->mlx_ptr, var->width_win,
			var->height_win, "My Window");
	var->img_ptr_wall = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/wall.xpm", &width_img, &height_img);
	var->img_ptr_ground = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/ground.xpm", &width_img, &height_img);
	var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/collectible.xpm", &width_img, &height_img);
	var->img_ptr_exit = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/exit.xpm", &width_img, &height_img);
	var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/player_down.xpm", &width_img, &height_img);
	var->score = 0;
}

int	main(int argc, char **argv)
{
	t_var	*var;
	int		fd;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		write(2, "You should only be used 2 arg.\n", 31);
		exit (0);
	}
	fd = open(argv[argc - 1], O_RDWR);
	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		return (0);
	fill_map_in_matrix(var, fd, argv);
	initialisation(var);
	protect_img(var);
	map(var);
	mlx_hook(var->win_ptr, 2, 0, &handle_key_press, var);
	mlx_hook(var->win_ptr, 17, 0, &destroy_notify_handler, var);
	mlx_loop(var->mlx_ptr);
	return (0);
}
