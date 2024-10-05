/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:42:28 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/05 12:35:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack, char *op)
{
	int	temp;

	if (stack->top < 1)
	{
		print_error("op ID: S", stack->id);
		return ;
	}
	temp = stack->collection[stack->top];
	stack->collection[stack->top] = stack->collection[stack->top - 1];
	stack->collection[stack->top - 1] = temp;
	if (*op)
		ft_printf("%s\n", op);
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, "\0");
	swap(stack_b, "\0");
	ft_printf("ss\n");
}
