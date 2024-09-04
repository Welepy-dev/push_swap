/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:03:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/04 15:10:33 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    choose_sort(t_stack *stack_a, t_stack *stack_b)
{
        if (stack_a->top == 2)
                tiny_sort(stack_a, 'a');
        else if (stack_a->top == 1)
                super_tiny_sort(stack_a, 'a');
        else
                turk_sort(stack_a, stack_b);
}