/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:22:28 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 16:49:27 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate_a(t_stack **stack_a, t_stack *s_a)
{
	while (s_a->index > 0)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
		(s_a->index)--;
	}
}

void	do_rotate_b(t_stack **stack_b, t_stack *s_b)
{
	while (s_b->index > 0)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
		(s_b->index)--;
	}
}

void	do_reverse_rotate_a(t_stack **stack_a, t_stack *s_a)
{
	while (s_a->index < t_stack_size(*stack_a))
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
		(s_a->index)++;
	}
}

void	do_reverse_rotate_b(t_stack **stack_b, t_stack *s_b)
{
	while (s_b->index < t_stack_size(*stack_b))
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
		(s_b->index)++;
	}
}
