/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:08:55 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 17:41:15 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_number(char *number)
{
	int	j;
	int	signe;

	j = 0;
	signe = 0;
	while (number[j])
	{
		if (number[j] == '-' || number[j] == '+')
		{
			if (number[j + 1] == ' ')
				return (write(2, "Error\n", 6), 0);
			j++;
		}
		if ((number[j] < '0' || number[j] > '9') && number[j] != ' ')
			return (write(2, "Error\n", 6), 0);
		if (number[j] >= '0' && number[j] <= '9')
			signe = 1;
		j++;
	}
	if (signe == 0)
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	*fill_arr(int argc, char **argv, int count_num)
{
	int		*arr;
	char	**str;
	int		j;
	int		i;

	i = 1;
	arr = malloc(sizeof(int) * count_num);
	if (!arr)
		return (NULL);
	count_num = 0;
	while (argc-- > 1)
	{
		j = 0;
		str = ft_split(argv[i], ' ');
		while (str[j])
			arr[count_num++] = ft_atoi(str[j++]);
		j = 0;
		while (str[j])
			free(str[j++]);
		free(str);
		i++;
	}
	return (arr);
}

int	check_deplicate(int *arr, int count_num)
{
	int	i;
	int	j;

	i = 0;
	while (i < count_num)
	{
		j = i + 1;
		while (j < count_num)
		{
			if (arr[i] == arr[j])
				return (write(2, "Error\n", 6), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_is_integer(char *number)
{
	long	num;

	num = ft_atoi(number);
	if (num > INT_MAX || num < INT_MIN)
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	check_is_number_and_integer(int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;
	int		count_num;

	count_num = 0;
	i = 1;
	while (argc-- > 1)
	{
		if (check_is_number(argv[i]) == 0)
			return (0);
		j = 0;
		str = ft_split(argv[i++], ' ');
		while (str[j])
		{
			if (check_is_integer(str[j++]) == 0)
				return (0);
			count_num++;
		}
		j = 0;
		while (str[j])
			free(str[j++]);
		free(str);
	}
	return (count_num);
}
