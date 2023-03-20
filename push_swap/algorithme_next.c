/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:34:58 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 15:28:54 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_movement(t_stack *stack_b)
{
	int	min;

	min = stack_b->status;
	while (stack_b)
	{
		if (min > stack_b->status)
			min = stack_b->status;
		stack_b = stack_b->next;
	}
	return (min);
}

void	move_to_stack_a(t_stack **stack_a, t_stack **stack_b,
			int *arr, int edge_of_arr)
{
	reset_status(*stack_b);
	reset_movement(*stack_a, *stack_b, arr, edge_of_arr);
	while (t_stack_size(*stack_b) != 0)
	{
		move_to_stack_a_next(stack_a, stack_b, arr, edge_of_arr);
		reset_status(*stack_b);
		reset_movement(*stack_a, *stack_b, arr, edge_of_arr);
	}
}

void	move_to_stack_a_next1(t_stack **stack_a, t_stack **stack_b,
			t_stack *s_a, t_stack *s_b)
{
	if (s_a->index <= (t_stack_size(*stack_a) / 2))
		do_rotate_a(stack_a, s_a);
	else if (s_a->index > (t_stack_size(*stack_a) / 2))
		do_reverse_rotate_a(stack_a, s_a);
	if (s_b->index <= (t_stack_size(*stack_b) / 2))
		do_rotate_b(stack_b, s_b);
	else if (s_b->index > (t_stack_size(*stack_b) / 2))
		do_reverse_rotate_b(stack_b, s_b);
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	reset_index(*stack_a);
	reset_index(*stack_b);
}

void	move_to_stack_a_next(t_stack **stack_a, t_stack **stack_b,
			int *arr, int edge_of_arr)
{
	int		number;
	t_stack	*s_a;
	t_stack	*s_b;

	s_a = *stack_a;
	s_b = *stack_b;
	while (s_b)
	{
		if (min_movement(*stack_b) == s_b->status)
			break ;
		s_b = s_b->next;
	}
	number = find_next_number_in_arr(*stack_a, s_b->number, arr, edge_of_arr);
	while (s_a)
	{
		if (s_a->number == number)
			break ;
		s_a = s_a->next;
	}
	same_move(stack_a, stack_b, s_b, s_a);
	reset_index(*stack_a);
	reset_index(*stack_b);
	move_to_stack_a_next1(stack_a, stack_b, s_a, s_b);
}
