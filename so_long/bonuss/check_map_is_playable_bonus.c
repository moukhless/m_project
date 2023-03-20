/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_playable_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:51:28 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 01:35:05 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_is_playable_bonus(t_var *var)
{
	int		check_x;
	int		check_y;
	char	**matrix;

	matrix = (char **)malloc(sizeof(char *) * ((var->height_win / 60) + 1));
	if (!matrix)
		free_all_and_exit_bonus(var);
	fill_matrix_bonus(var, matrix);
	mark_position_of_player_bonus(var, &check_x, &check_y, matrix);
	check_path_of_player_bonus(var, check_x, check_y, matrix);
	check_map_is_playable_next_bonus(var, matrix);
	free_matrix_bonus(matrix);
}

void	check_path_of_player_bonus(t_var *var, int check_x,
			int check_y, char **matrix)
{
	matrix[check_y][check_x] = '1';
	if (var->str[check_y - 1][check_x] != '1'
		&& var->str[check_y - 1][check_x] != 'E'
		&& matrix[check_y - 1][check_x] == '0')
		check_path_of_player_bonus(var, check_x, check_y - 1, matrix);
	if (var->str[check_y][check_x - 1] != '1'
		&& var->str[check_y][check_x - 1] != 'E'
		&& matrix[check_y][check_x - 1] == '0')
		check_path_of_player_bonus(var, check_x - 1, check_y, matrix);
	if (var->str[check_y + 1][check_x] != '1'
		&& var->str[check_y + 1][check_x] != 'E'
		&& matrix[check_y + 1][check_x] == '0')
		check_path_of_player_bonus(var, check_x, check_y + 1, matrix);
	if (var->str[check_y][check_x + 1] != '1'
		&& var->str[check_y][check_x + 1] != 'E'
		&& matrix[check_y][check_x + 1] == '0')
		check_path_of_player_bonus(var, check_x + 1, check_y, matrix);
}

void	free_matrix_bonus(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix[i]);
	free(matrix);
}

void	check_map_is_playable_next_bonus(t_var *var, char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->height_win / 60)
	{
		j = 0;
		while (j < var->width_win / 60)
		{
			if ((var->str[i][j] == 'C' && matrix[i][j] == '0')
					|| (var->str[i][j] == 'E' && (matrix[i - 1][j] == '0'
						&& matrix[i + 1][j] == '0' && matrix[i][j - 1] == '0'
						&& matrix[i][j + 1] == '0')))
			{
				write(2, "ERROR\n", 6);
				write(2, "Your map is not playble.\n", 25);
				free_matrix_bonus(matrix);
				free_all_and_exit_bonus(var);
			}
			j++;
		}
		i++;
	}
}

void	mark_position_of_player_bonus(t_var *var, int *check_x,
			int *check_y, char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (var->str[i])
	{
		j = 0;
		while (var->str[i][j])
		{
			if (var->str[i][j] == 'P')
			{
				*check_y = i;
				*check_x = j;
				matrix[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}
