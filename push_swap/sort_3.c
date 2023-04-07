/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:37:15 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 22:49:16 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size_3_next2(t_stack **stack_a,
			int index_max, int index_min)
{
	if (index_max == 0 && index_min == 1)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	else if (index_max == 0 && index_min == 2)
	{
		rotate(stack_a);
		swap(stack_a);
		write(1, "ra\n", 3);
		write(1, "sa\n", 3);
	}
}

void	sort_stack_size_3_next1(t_stack **stack_a,
			int index_max, int index_min)
{
	if (index_max == 1 && index_min == 0)
	{
		reverse_rotate(stack_a);
		swap(stack_a);
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
	}
	else if (index_max == 2 && index_min == 1)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (index_max == 1 && index_min == 2)
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	else
		sort_stack_size_3_next2(stack_a, index_max, index_min);
}

void	sort_stack_size_3(t_stack **stack_a)
{
	t_stack	*s_a;
	int		min;
	int		max;

	min = (*stack_a)->number;
	max = (*stack_a)->number;
	s_a = (*stack_a);
	while (s_a)
	{
		if (min > s_a->number)
			min = s_a->number;
		if (max < s_a->number)
			max = s_a->number;
		s_a = s_a->next;
	}
	reset_index(*stack_a);
	s_a = *stack_a;
	sort_stack_size_3_next(stack_a, s_a, min, max);
}

void	sort_stack_size_3_next(t_stack **stack_a,
		t_stack *s_a, int min, int max)
{
	int		index_min;
	int		index_max;

	while (s_a)
	{
		if (s_a->number == min)
			index_min = s_a->index;
		if (s_a->number == max)
			index_max = s_a->index;
		s_a = s_a->next;
	}
	sort_stack_size_3_next1(stack_a, index_max, index_min);
}
