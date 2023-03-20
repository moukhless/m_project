/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:48:57 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 02:02:58 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strcmp_bonus(char *str1, char *str2)
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

void	check_map_type_bonus(char *str)
{
	int		i;
	int		j;
	char	*type;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			j = 0;
			type = malloc(4);
			while (j < 3)
				type[j++] = str[i++];
			type[j] = '\0';
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
	if (i - j != 3 || ft_strcmp_bonus(type, "ber") != 0)
	{
		write(2, "ERROR\n", 6);
		write(2, "Type of file is not valide\n", 28);
		free(type);
		exit (0);
	}
	else
		free(type);
}

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
