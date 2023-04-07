/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:47:18 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 22:50:34 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
