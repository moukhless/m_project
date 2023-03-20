/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_support1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:25:23 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 16:58:42 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr, int count_num)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < count_num)
	{
		j = 0;
		while (j < count_num)
		{
			if (arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	check_stack_sorted(t_stack *s_list)
{
	t_stack	*p;

	p = s_list->next;
	while (p)
	{
		if (s_list->number > p->number)
			return (0);
		s_list = p;
		p = s_list->next;
	}
	return (1);
}

int	longest_list(t_stack *stack_a)
{
	int		max;
	t_stack	*p;

	max = stack_a->status;
	while (stack_a)
	{
		p = stack_a->next;
		while (p)
		{
			if (stack_a->status < p->status && p->status > max)
				max = p->status;
			p = p->next;
		}
		stack_a = stack_a->next;
	}
	return (max);
}

void	reset_index(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->index = i++;
		stack_a = stack_a->next;
	}
}

int	find_number_in_arr(int number, int *arr, int edge_of_arr)
{
	int	i;

	i = 0;
	while (i <= edge_of_arr)
	{
		if (number == arr[i])
			return (1);
		i++;
	}
	return (0);
}
