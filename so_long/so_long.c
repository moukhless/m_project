/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:27:08 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/22 08:09:50 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	check_map_type(char *str)
{
	int		i;
	int		j;
	char	*type;

	i = 0;
	type = NULL;
	i = get_point(str);
	j = i + 1;
	while (str[i])
		i++;
	type = malloc(i - j + 1);
	i = j;
	j = 0;
	while (str[i])
		type[j++] = str[i++];
	type[j] = '\0';
	check_map_type_next(type);
}

void	check_map_type_next(char *type)
{
	if (type == NULL || ft_strcmp(type, "ber") != 0)
	{
		write(2, "ERROR\n", 6);
		write(2, "Type of file is not valide\n", 27);
		free(type);
		exit (0);
	}
	else
		free(type);
}

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
	check_map_type(argv[argc - 1]);
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
