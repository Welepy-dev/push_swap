/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:15:09 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/01 12:33:02 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *stack, char *op)
{
	int	temp;

	if (stack->top < 1)
		print_error();
	else
	{
		temp = pop(stack);
		ft_memmove(&stack->collection[1], &stack->collection[0], \
				(stack->capacity - 1) * sizeof(int));
		stack->collection[0] = temp;
	}
	if (*op)
		ft_printf("%s\n", op);
}

void	reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse(stack_a, "\0");
	reverse(stack_b, "\0");
	ft_printf("rr");
}

void	reverse_reverse(t_stack *stack, char *op)
{
	int	temp;

	if (stack->top < 1)
		print_error();
	else
	{
		temp = stack->collection[0];
		ft_memmove(&stack->collection[0], &stack->collection[1], \
				(stack->capacity - 1) * sizeof(int));
		stack->collection[stack->top] = temp;
	}
	if (*op)
		ft_printf("%s\n", op);
}

void	reverse_reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_reverse(stack_a, "\0");
	reverse_reverse(stack_b, "\0");
	ft_printf("rrr");
}
