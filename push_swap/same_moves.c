/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:26:27 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/16 14:26:48 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void do_same_move1(t_stack **stack_a, t_stack **stack_b, t_stack *s_b, t_stack *s_a)
{
    int move;
    int size;

    move = s_a->index;
    if (s_a->index > s_b->index)
        move = s_b->index;
    while (move > 0)
    {
        rotate(stack_a);
        rotate(stack_b);
        write(1, "rr\n", 3);
        move--;
    }
}

void do_same_move2(t_stack **stack_a, t_stack **stack_b, t_stack *s_b, t_stack *s_a)
{
    int move;
    int size;

    move = s_a->index;
    size = t_stack_size(*stack_a);
    if ((t_stack_size(*stack_a) - s_a->index) > (t_stack_size(*stack_b) - s_b->index))
    {
        move = s_b->index;
        size = t_stack_size(*stack_b);
    }
    while (move < size)
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
        write(1, "rrr\n", 4);
        move++;
    }
}

void same_move(t_stack **stack_a, t_stack **stack_b, t_stack *s_b, t_stack *s_a)
{
    if (s_a->index != 0 && s_b->index != 0)
    {
        if (s_a->index <= (t_stack_size(*stack_a) / 2) && s_b->index <= (t_stack_size(*stack_b) / 2))
            do_same_move1(stack_a, stack_b, s_b, s_a);
        else if (s_a->index > (t_stack_size(*stack_a) / 2) && s_b->index > (t_stack_size(*stack_b) / 2))
            do_same_move2(stack_a, stack_b, s_b, s_a);
    }
}   