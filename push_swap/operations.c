/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:07:40 by amoukhle          #+#    #+#             */
/*   Updated: 2023/01/26 20:07:45 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **s_list)
{
    t_stack *p;
    
    p = *s_list;
    *s_list = (*s_list)->next;
    p->next = (*s_list)->next;
    (*s_list)->next = p;
}

void push(t_stack **s_list_a, t_stack **s_list_b)
{
    t_stack *p;
    
    p = *s_list_a;
    *s_list_a = (*s_list_a)->next;
    p->next = *s_list_b;
    *s_list_b = p;    
}

void rotate(t_stack **s_list)
{
    t_stack *p;
    t_stack *p1;
    
    p = *s_list;
    p1 = *s_list;
    *s_list = (*s_list)->next;
    while (p1->next)
        p1 = p1->next;
    p1->next = p;
    p->next = NULL;
}

void reverse_rotate(t_stack **s_list)
{
    t_stack *p;
    t_stack *p1;

    p = *s_list;
    p1 = *s_list;
    while (p->next)
        p = p->next;
    p->next = *s_list;
    while (p1->next != p)
        p1 = p1->next;
    p1->next = NULL;
    *s_list = p;
}