/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:15:09 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/04 15:38:58 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char *op)
{
	int	temp;

	if (stack->top < 1)
	{
		ft_printf("Error 6\n");
		print_error();
	}
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

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, "\0");
	rotate(stack_b, "\0");
	ft_printf("rr");
}

void	reverse_rotate(t_stack *stack, char *op)
{
	int	temp;

	if (stack->top < 1)
	{
		ft_printf("Error 7\n");
		print_error();
	}
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

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, "\0");
	reverse_rotate(stack_b, "\0");
	ft_printf("rrr");
}
