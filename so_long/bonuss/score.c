/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:17:51 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/07 22:41:55 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_num(int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*itoa(int num)
{
	int		count;
	char	*score;
	int		i;

	count = count_num(num);
	i = count - 1;
	score = malloc(count + 1);
	if (!score)
		return (NULL);
	score[count] = '\0';
	while (i >= 0)
	{
		score[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (score);
}

char	*ft_strdup(char *src)
{
	char	*n_str;
	int		i;

	i = 0;
	n_str = (char *)malloc((ft_strlen(src) + 1));
	if (!n_str)
		return (NULL);
	while (src[i])
	{
		n_str[i] = src[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}

char	*scores(t_var *var, int num)
{
	char	*str;
	char	*nums;

	nums = itoa(num);
	str = ft_strdup("Score : ");
	str = ft_strjoin(str, nums);
	free(nums);
	mlx_string_put(var->mlx_ptr, var->win_ptr, 120, 0, var->color, str);
	return (str);
}
