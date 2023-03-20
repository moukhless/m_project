/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:47:18 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 20:07:02 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_size_3_next(t_stack **stack_a,
			t_stack **stack_b, t_stack *s_a)
{
	if (s_a->index == 0)
	{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	else
	{
		if (s_a->index <= (t_stack_size(*stack_a) / 2))
			do_rotate_a(stack_a, s_a);
		else if (s_a->index > (t_stack_size(*stack_a) / 2))
			do_reverse_rotate_a(stack_a, s_a);
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	if (check_stack_sorted(*stack_a) == 0)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	sort_stack_size_3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*s_a;
	int		min;

	min = (*stack_a)->number;
	s_a = (*stack_a);
	while (s_a)
	{
		if (min > s_a->number)
			min = s_a->number;
		s_a = s_a->next;
	}
	s_a = *stack_a;
	while (s_a->number != min)
		s_a = s_a->next;
	sort_stack_size_3_next(stack_a, stack_b, s_a);
}

void	sort_stack_size_5_next(t_stack *stack_a, t_stack *stack_b,
			int *arr, int edge_of_arr)
{
	t_stack	*s_a;
	t_stack	*s_b;
	int		num;

	while (t_stack_size(stack_b) != 0)
	{
		s_b = stack_b;
		s_a = stack_a;
		num = find_next_number_in_arr(stack_a, s_b->number,
				arr, edge_of_arr);
		while (s_a)
		{
			if (s_a->number == num)
				break ;
			s_a = s_a->next;
		}
		same_move(&stack_a, &stack_b, s_b, s_a);
		reset_index(stack_a);
		reset_index(stack_b);
		move_to_stack_a_next1(&stack_a, &stack_b, s_a, s_b);
	}
}

void	sort_stack_size_5(t_stack *stack_a, t_stack *stack_b,
			int *arr, int edge_of_arr)
{
	push(&stack_a, &stack_b);
	write(1, "pb\n", 3);
	push(&stack_a, &stack_b);
	write(1, "pb\n", 3);
	push(&stack_a, &stack_b);
	write(1, "pb\n", 3);
	reset_index(stack_a);
	reset_index(stack_b);
	sort_stack_size_5_next(stack_a, stack_b, arr, edge_of_arr);
}
