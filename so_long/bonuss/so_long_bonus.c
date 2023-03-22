/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:22:31 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/22 08:10:10 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	protect_img_enemy_bonus(t_var *var)
{
	if (!var->img_ptr_wall || !var->img_ptr_ground || !var->img_ptr_coll
		|| !var->img_ptr_exit || !var->img_ptr_player || !var->img_ptr_enemy)
	{
		write(2, "ERROR\n", 6);
		write(2, "Can't access to image.\n", 23);
		t_enemy_clean(&(var->enemy));
		free_all_and_exit_bonus(var);
	}
	if (!var->mlx_ptr || !var->win_ptr)
	{
		write(2, "ERROR\n", 6);
		write(2, "Problem in alocation\n", 21);
		t_enemy_clean(&(var->enemy));
		free_all_and_exit_bonus(var);
	}
}

void	initialisation_bonus(t_var *var)
{
	int		width_img;
	int		height_img;

	var->color = 0x00FFFFFF;
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
			"textures/player_right1.xpm", &width_img, &height_img);
	var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr,
			"textures/enemy_up.xpm", &width_img, &height_img);
}

int	drawing_map(t_var *var)
{
	static int	count;
	static int	count_e;
	static int	count_exit;
	static int	score;

	var->score = &score;
	count++;
	count_e++;
	animation_of_coll_and_exit(var, &count, &count_exit);
	map_bonus(var);
	animation_of_enemy(var, &count_e);
	t_enemy_clean(&(var->enemy));
	mlx_hook(var->win_ptr, 2, 0, &handle_key_press_bonus, var);
	var->s = scores(var, *(var->score));
	free(var->s);
	return (0);
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
	check_map_type_bonus(argv[argc - 1]);
	fd = open(argv[argc - 1], O_RDWR);
	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		return (-1);
	fill_map_in_matrix_bonus(var, fd, argv);
	initialisation_bonus(var);
	protect_img_bonus(var);
	mlx_loop_hook(var->mlx_ptr, &drawing_map, var);
	mlx_hook(var->win_ptr, 17, 0, &destroy_notify_handler, var);
	mlx_loop(var->mlx_ptr);
	return (0);
}
