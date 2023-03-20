/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:40:06 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 19:56:46 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_movement(t_stack *stack_a, t_stack *stack_b,
			int *arr, int edge_of_arr)
{
	t_stack	*s_b;
	t_stack	*s_a;
	int		number;

	s_b = stack_b;
	s_a = stack_a;
	while (s_b)
	{
		number = find_next_number_in_arr(stack_a, s_b->number,
				arr, edge_of_arr);
		while (s_a->number != number)
			s_a = s_a->next;
		if (s_a->index <= (t_stack_size(stack_a) / 2)
			&& s_b->index > (t_stack_size(stack_b) / 2))
			calcul_mov1(s_b, s_a, stack_b);
		else if (s_a->index > (t_stack_size(stack_a) / 2)
			&& s_b->index <= (t_stack_size(stack_b) / 2))
			calcul_mov2(s_b, s_a, stack_a, stack_b);
		else
			reset_movement_next(stack_a, stack_b, s_a, s_b);
		s_a = stack_a;
		s_b = s_b->next;
	}
}

void	reset_movement_next(t_stack *stack_a, t_stack *stack_b,
			t_stack *s_a, t_stack *s_b)
{
	if (s_a->index <= (t_stack_size(stack_a) / 2)
		&& s_b->index <= (t_stack_size(stack_b) / 2))
		calcul_mov3(s_b, s_a);
	else if (s_a->index > (t_stack_size(stack_a) / 2)
		&& s_b->index > (t_stack_size(stack_b) / 2))
		calcul_mov4(s_b, s_a, stack_a, stack_b);
}
