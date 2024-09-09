/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:53:36 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/09 12:33:41 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack, char *op)
{
	int	temp1;
	int	temp2;

	if (stack->top < 1)
	{
		ft_printf("Error 3\n");
		print_error();
	}
	temp1 = pop(stack);
	temp2 = pop(stack);
	insert(stack, temp1);
	insert(stack, temp2);
	if (*op)
		ft_printf("%s\n", op);
	return (0);
}

int	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, "\0");
	swap(stack_b, "\0");
	ft_printf("ss\n");
	return (0);
}

int	push(t_stack *src, t_stack *dst, char *op)
{
	if (is_full(dst))
	{
		ft_printf("Error 4\n");
		print_error();
	}
	dst->top++;
	dst->collection[dst->top] = src->collection[src->top];
	src->top--;
	ft_printf("%s\n", op);
	return (0);
}

void	insert(t_stack *stack, int item)
{
	if (is_full(stack))
	{
		ft_printf("Error 5\n");
		print_error();
	}
	stack->collection[++stack->top] = item;
}
