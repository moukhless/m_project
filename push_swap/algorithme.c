/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:43:08 by amoukhle          #+#    #+#             */
/*   Updated: 2023/02/10 02:22:56 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void longest_increasing_subsequence(t_stack *stack_a)
{
    t_stack *p;
    t_stack *head;
    
    p = stack_a;
    head = stack_a;
    while (stack_a)
    {
        while (p != stack_a)
        {
            if (stack_a->number > p->number)
            {
                if (stack_a->status < ((p->status) + 1))
                {
                    stack_a->status = (p->status) + 1;
                    stack_a->next_index = p->index;
                }
            }
            p = p->next;
        }
        p = head;
        stack_a = stack_a->next;
    }
}

int *arr_longest_list(t_stack *stack_a)
{
    int *arr;
    int i;
    int j;
    t_stack *p;

    j = longest_list(stack_a) - 1;
    p = stack_a;
    arr = malloc(sizeof(int) * longest_list(stack_a));
    if (!arr)
        return (NULL);
    while (p->status != longest_list(stack_a))
        p = p->next;
    while (p->next_index != t_stack_size(stack_a))
    {
        arr[j--] = p->number;
        i = p->next_index;
        p = stack_a;
        while (p->index != i)
            p = p->next;
    }
    arr[j] = p->number;
    return (arr);
}

void move_to_stack_b(t_stack **stack_a , t_stack **stack_b)
{
    t_stack *p;
    int *arr;
    
    p = *stack_a;
    arr = arr_longest_list(p);
    while (p)
    {
        if (find_number_in_arr(p->number, arr, longest_list(*stack_a) - 1) == 1)
            p = p->next;
        else
        {
            move_to_stack_b_next(p, stack_a, stack_b);
            p = *stack_a;
        }
    }
    free(arr);
}

void move_to_stack_b_next(t_stack *p ,t_stack **stack_a, t_stack **stack_b)
{
    if (p->index == 0)
    {
        push(stack_a, stack_b);
        write(1, "pb\n", 3);
        reset_index(*stack_a);
        reset_index(*stack_b); 
    } 
    else
        move_to_stack_b_next1(p, stack_a, stack_b);
}

void move_to_stack_b_next1(t_stack *p ,t_stack **stack_a, t_stack **stack_b)
{
    if (p->index <= (t_stack_size(*stack_a) / 2))
    {
        while ((p->index)-- > 0)
        {
            rotate(stack_a);
            write(1, "ra\n", 3);
        }
    }
    else if (p->index > (t_stack_size(*stack_a) / 2))
    {
        while ((p->index)++ < t_stack_size(*stack_a))
        {
            reverse_rotate(stack_a);
            write(1, "rra\n", 4);
        }
    }
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
    reset_index(*stack_a);
    reset_index(*stack_b);
}