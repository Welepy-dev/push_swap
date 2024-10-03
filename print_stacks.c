/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:37:02 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 19:13:15 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rendu/push_swap.h"

void print_stacks(t_stack *stack_a, t_stack *stack_b) {
    int i, max_height;

    ft_printf("Stacks Overview:\n\n");
    ft_printf("  Stack A        Stack B\n");
    ft_printf("-------------------------\n");

    // Find the larger of the two stacks to iterate through
    max_height = (stack_a->top > stack_b->top) ? stack_a->top : stack_b->top;

    for (i = max_height; i >= 0 ; i--) {
        // Print Stack A value or a placeholder if the stack is shorter
        if (i <= stack_a->top) {
            ft_printf("%d", stack_a->collection[i]);
        } else {
            ft_printf("          ");  // 10 spaces for alignment
        }

        ft_printf("           |           ");

        // Print Stack B value or a placeholder if the stack is shorter
        if (i <= stack_b->top) {
            ft_printf("%d", stack_b->collection[i]);
        } else {
            ft_printf("          ");  // 10 spaces for alignment
        }

        ft_printf("\n");
    }

    ft_printf("-------------------------\n");
    ft_printf("Top num A: %d       Top num B: %d\n", 
              stack_a->top >= 0 ? stack_a->collection[stack_a->top] : -1, 
              stack_b->top >= 0 ? stack_b->collection[stack_b->top] : -1);
    ft_printf("Cap A: %d           Cap B: %d\n", stack_a->capacity, stack_b->capacity);
    ft_printf("Top idx A: %d       Top dx B: %d\n", stack_a->top, stack_b->top);
    ft_printf("Counter A: %d       Counter B: %d\n", stack_a->counter, stack_b->counter);
    ft_printf("\n");
}
