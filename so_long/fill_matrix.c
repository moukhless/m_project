/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:30:09 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/07 19:54:06 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_matrix(t_var *var, char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->height_win / 60)
	{
		j = 0;
		matrix[i] = malloc(var->width_win / 60 + 1);
		if (!matrix[i])
		{
			free_matrix(matrix);
			free_all_and_exit(var);
		}
		while (j < var->width_win / 60)
			matrix[i][j++] = '0';
		matrix[i++][j] = '\0';
	}
	matrix[i] = NULL;
}
