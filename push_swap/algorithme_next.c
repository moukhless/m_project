/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:34:58 by amoukhle          #+#    #+#             */
/*   Updated: 2023/02/10 02:25:44 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reset_movement(t_stack *stack_a, t_stack *stack_b, int *arr, int edge_of_arr)
{
    t_stack *p;
    t_stack *p1;
    int number;

    p = stack_b;
    p1 = stack_a;
    while (p)
    {
        number = find_next_number_in_arr(stack_a ,p->number, arr, edge_of_arr);
        if (find_number_in_stack(number, stack_a) == 1)
        {
            while (p1->number != number)
                p1 = p1->next;
            if (p1->index <= (t_stack_size(stack_a) / 2))
            {
                p->status = p1->index;
                if (p->index <= (t_stack_size(stack_b)) / 2)
                {
                    if (p->index == 0)
                        p->status = p->status + 1;
                    else
                        p->status = p->status + p->index + 1;
                }
                else if (p->index > (t_stack_size(stack_b) / 2))
                    p->status = p->status + t_stack_size(stack_b) - p->index + 1;
            }
            else if (p1->index > (t_stack_size(stack_a) / 2))
            {
                p->status = t_stack_size(stack_a) - p1->index;
                if (p->index <= (t_stack_size(stack_b)) / 2)
                {
                    if (p->index == 0)
                        p->status = p->status + 1;
                    else
                        p->status = p->status + p->index + 1;
                }
                else if (p->index > (t_stack_size(stack_b) / 2))
                    p->status = p->status + t_stack_size(stack_b) - p->index + 1;
            }
            p1 = stack_a;
        }
        p = p->next;
    }
}

int min_movement(t_stack *stack_b)
{
    int min;
    
    min = stack_b->status;
    while (stack_b)
    {
        if (min == 0 && stack_b->status != 0)
            min = stack_b->status;
        else if (min > stack_b->status && stack_b->status != 0)
            min = stack_b->status;
        stack_b = stack_b->next;
    }
    return (min);
}

void move_to_stack_a(t_stack **stack_a, t_stack **stack_b, int *arr, int edge_of_arr)
{
    t_stack *p;

    p = *stack_b;
    reset_status(*stack_b);
    reset_movement(*stack_a, *stack_b, arr, edge_of_arr);
    while (t_stack_size(*stack_b) != 0)
    {
    //     printf("stack a\n");
    // affiche_stack(*stack_a);
    // printf("stack b\n");
    // affiche_stack(*stack_b);
        move_to_stack_a_next(stack_a, stack_b, arr, edge_of_arr);
        reset_status(*stack_b);
        reset_movement(*stack_a, *stack_b, arr, edge_of_arr);
    }
}

void same_move(t_stack **stack_a, t_stack **stack_b, t_stack *p, t_stack *p1)
{
    int move;
    int size;

    if (p1->index != 0 && p->index != 0)
    {
        if (p1->index <= (t_stack_size(*stack_a) / 2) && p->index <= (t_stack_size(*stack_b) / 2))
        {
            move = p1->index;
            if (p1->index > p->index)
                move = p->index;
            while (move > 0)
            {
                rotate(stack_a);
                rotate(stack_b);
                write(1, "rr\n", 3);
                move--;
            }
        }
        else if (p1->index > (t_stack_size(*stack_a) / 2) && p->index > (t_stack_size(*stack_b) / 2))
        {
            move = p1->index;
            size = t_stack_size(*stack_a);
            if (p1->index < p->index)
            {
                move = p->index;
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
    }
}   

void move_to_stack_a_next(t_stack **stack_a, t_stack **stack_b, int *arr, int edge_of_arr)
{
    int number;
    t_stack *p1;
    t_stack *p;

    p1 = *stack_a;
    p = *stack_b;
    
    while (p)
    {
        if (min_movement(*stack_b) == p->status)
            break;
        p = p->next;
    }
    number = find_next_number_in_arr(*stack_a ,p->number, arr, edge_of_arr);
    while (p1)
    {
        if (p1->number == number)
            break;
        p1 = p1->next;
    }
    same_move(stack_a, stack_b, p, p1);
    reset_index(*stack_a);
    reset_index(*stack_b);
    if (p1->index <= (t_stack_size(*stack_a) / 2) && p1->index != 0)
    {
        while ((p1->index)-- > 0)
        {
            rotate(stack_a);
            write(1, "ra\n", 3);
        }
    }
    else if (p1->index > (t_stack_size(*stack_a) / 2))
    {
        while ((p1->index)++ < t_stack_size(*stack_a))
        {
            reverse_rotate(stack_a);
            write(1, "rra\n", 4);
        }
    }
    if (p->index <= (t_stack_size(*stack_b) / 2) && p->index != 0)
    {
        while ((p->index)-- > 0)
        {
            rotate(stack_b);
            write(1, "rb\n", 3);
        }
    }
    else if (p->index > (t_stack_size(*stack_b) / 2))
    {
        while ((p->index)++ < t_stack_size(*stack_b))
        {
            reverse_rotate(stack_b);
            write(1, "rrb\n", 4);
        }
    }
    push(stack_b, stack_a);
    write(1, "pa\n", 3);
    reset_index(*stack_a);
    reset_index(*stack_b);
}