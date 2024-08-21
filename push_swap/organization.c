/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:53:36 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/03 17:12:36 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack, char *op)
{
	int	temp1;
	int	temp2;

	if (stack->top < 1)
		print_error();
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
	int	temp;

	if (is_full(src))
		print_error();
	temp = pop(src);
	dst->collection[++dst->top] = temp;
	if (*op)
		ft_printf("%s\n", op);
	return (0);
}
