/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:24:18 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 15:56:10 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_mov1(t_stack *s_b, t_stack *s_a, t_stack *stack_b)
{
	s_b->status = s_a->index;
	if (s_b->index <= (t_stack_size(stack_b)) / 2)
		s_b->status = s_b->status + s_b->index + 1;
	else if (s_b->index > (t_stack_size(stack_b) / 2))
		s_b->status = s_b->status + t_stack_size(stack_b) - s_b->index + 1;
}

void	calcul_mov2(t_stack *s_b, t_stack *s_a,
			t_stack *stack_a, t_stack *stack_b)
{
	s_b->status = t_stack_size(stack_a) - s_a->index;
	if (s_b->index <= (t_stack_size(stack_b)) / 2)
		s_b->status = s_b->status + s_b->index + 1;
	else if (s_b->index > (t_stack_size(stack_b) / 2))
		s_b->status = s_b->status + t_stack_size(stack_b) - s_b->index + 1;
}

void	calcul_mov3(t_stack *s_b, t_stack *s_a)
{
	if (s_a->index <= s_b->index)
		s_b->status = s_a->index + (s_b->index - s_a->index) + 1;
	else if (s_a->index > s_b->index)
		s_b->status = s_b->index + (s_a->index - s_b->index) + 1;
}

void	calcul_mov4(t_stack *s_b, t_stack *s_a,
			t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;
	int	rest;

	size_a = t_stack_size(stack_a);
	size_b = t_stack_size(stack_b);
	if ((size_a - s_a->index) <= (size_b - s_b->index))
	{
		rest = (size_b - s_b->index) - (size_a - s_a->index);
		s_b->status = (size_a - s_a->index) + rest + 1;
	}
	else if ((size_a - s_a->index) > (size_b - s_b->index))
	{
		rest = (size_a - s_a->index) - (size_b - s_b->index);
		s_b->status = (size_b - s_b->index) + rest + 1;
	}
}
