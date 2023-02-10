/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:15:51 by amoukhle          #+#    #+#             */
/*   Updated: 2023/02/10 02:22:23 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void affiche_stack(t_stack *stack)
{
    while (stack)
    {
        printf("number : %d, index : %d, status : %d, next_index : %d\n", stack->number, stack->index, stack->status, stack->next_index);
        stack = stack->next;
    }
}

int main(int argc, char **argv)
{
    int count_num;
    int *arr;
    int i;
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *p;
    
    
    count_num = check_is_number_and_integer(argc, argv);
    if (count_num == 0)
        return (0);
       
    arr = fill_arr(argc, argv, count_num);
    if (check_deplicate(arr) == 0)
        return (0);
    /*******************************************************/    
    i = 0;
    stack_b = NULL;
    stack_a = NULL;
    //fill stack_a
    while (i < count_num)
    {
        addnumber_back(&stack_a, new_number(arr[i], i, 1, count_num));
        i++;
    }
    p = stack_a;
    sort_arr(arr, count_num);
    i = 0;
    // while (i <= count_num - 1)
    // {
    //     printf("arr : %d\n", arr[i]);
    //     i++;
    // }
    longest_increasing_subsequence(stack_a);
    // affiche_stack(stack_a);
    move_to_stack_b(&stack_a, &stack_b);
    // printf("stack a\n");
    // affiche_stack(stack_a);
    //  printf("stack b\n");
    // affiche_stack(stack_b);
    move_to_stack_a(&stack_a, &stack_b, arr, count_num - 1);
    //  
    if (check_stack_sorted(stack_a) == 0)
        sort_stack(&stack_a, arr);
    // printf("%d\n", check_stack_sorted(stack_a));
    // affiche_stack(stack_a);
    free(arr);
    t_stack_clean(&stack_a);
    t_stack_clean(&stack_b);
//    system("leaks push_swap");
   return (0);
   
}