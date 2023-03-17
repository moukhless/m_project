/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:24:18 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/16 14:28:16 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reset_movement(t_stack *stack_a, t_stack *stack_b, int *arr, int edge_of_arr)
{
    t_stack *s_b;
    t_stack *s_a;
    int number;

    s_b = stack_b;
    s_a = stack_a;
    while (s_b)
    {
        number = find_next_number_in_arr(stack_a ,s_b->number, arr, edge_of_arr);
        while (s_a->number != number)
            s_a = s_a->next;
        if (s_a->index <= (t_stack_size(stack_a) / 2) && s_b->index > (t_stack_size(stack_b) / 2))
            calcul_mov1(s_b, s_a, stack_a, stack_b);
        else if (s_a->index > (t_stack_size(stack_a) / 2) && s_b->index <= (t_stack_size(stack_b) / 2))
            calcul_mov2(s_b, s_a, stack_a, stack_b);
        else if (s_a->index <= (t_stack_size(stack_a) / 2) && s_b->index <= (t_stack_size(stack_b) / 2))
            calcul_mov3(s_b, s_a, stack_a, stack_b);
        else if (s_a->index > (t_stack_size(stack_a) / 2) && s_b->index > (t_stack_size(stack_b) / 2))
            calcul_mov4(s_b, s_a, stack_a, stack_b);
        s_a = stack_a;
        s_b = s_b->next;
    }
}

void calcul_mov1(t_stack *s_b, t_stack *s_a, t_stack *stack_a, t_stack *stack_b)
{
    s_b->status = s_a->index;
    if (s_b->index <= (t_stack_size(stack_b)) / 2)
        s_b->status = s_b->status + s_b->index + 1;
    else if (s_b->index > (t_stack_size(stack_b) / 2))
        s_b->status = s_b->status + t_stack_size(stack_b) - s_b->index + 1;
}

void calcul_mov2(t_stack *s_b, t_stack *s_a, t_stack *stack_a, t_stack *stack_b)
{
    s_b->status = t_stack_size(stack_a) - s_a->index;
    if (s_b->index <= (t_stack_size(stack_b)) / 2)
            s_b->status = s_b->status + s_b->index + 1;
    else if (s_b->index > (t_stack_size(stack_b) / 2))
        s_b->status = s_b->status + t_stack_size(stack_b) - s_b->index + 1;
}

void calcul_mov3(t_stack *s_b, t_stack *s_a, t_stack *stack_a, t_stack *stack_b)
{
    if (s_a->index <= s_b->index)
        s_b->status = s_a->index + (s_b->index - s_a->index) + 1;
    else if (s_a->index > s_b->index)
        s_b->status = s_b->index + (s_a->index - s_b->index) + 1;
}

void calcul_mov4(t_stack *s_b, t_stack *s_a, t_stack *stack_a, t_stack *stack_b)
{
    if ((t_stack_size(stack_a) - s_a->index) <= (t_stack_size(stack_b) - s_b->index))
        s_b->status = (t_stack_size(stack_a) - s_a->index) + ((t_stack_size(stack_b) - s_b->index) - (t_stack_size(stack_a) - s_a->index)) + 1;
    else if ((t_stack_size(stack_a) - s_a->index) > (t_stack_size(stack_b) - s_b->index))
        s_b->status = (t_stack_size(stack_b) - s_b->index) + ((t_stack_size(stack_a) - s_a->index) - (t_stack_size(stack_b) - s_b->index)) + 1;
}