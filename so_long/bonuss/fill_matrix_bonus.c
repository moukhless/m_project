/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:48:57 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/08 22:50:39 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_matrix_bonus(t_var *var, char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->height_win / 60)
	{
		j = 0;
		matrix[i] = malloc(var->width_win / 60 + 1);
		if (!matrix)
		{
			free_matrix_bonus(matrix);
			free_all_and_exit_bonus(var);
		}
		while (j < var->width_win / 60)
			matrix[i][j++] = '0';
		matrix[i++][j] = '\0';
	}
	matrix[i] = NULL;
}
