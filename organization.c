/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:53:36 by marcsilv          #+#    #+#             */
/*   Updated: 2024/07/31 15:30:13 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *stack, int item, char *op)
{
	if (is_full(stack))
		printError();
	stack->collection[++stack->top] = item;
	if (*op)
		ft_printf("%s\n", op);
	return (0);
}

int	swap(t_stack *stack, char *op)
{
	int temp1;
	int temp2;
	if (stack->top < 1)
		printError();
	temp1 = pop(stack);
	temp2 = pop(stack);
	push(&stack, temp1, "\0");
	push(&stack, temp2, "\0");
	if (*op)
		ft_printf("%s\n", op);
	return (0);
}

int	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(&stack_a, "\0");
	swap(&stack_b, "\0");
	ft_printf("ss\n");
	return (0);	
}

