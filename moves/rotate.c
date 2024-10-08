/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:57:52 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/08 11:05:17 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *stack, char *op)
{
	int	temp;

	if (stack->top < 1)
		print_error("op ID: R", stack->id);
	else
	{
		temp = stack->collection[stack->top];
		ft_memmove(&stack->collection[1], \
		&stack->collection[0], stack->top * sizeof(int));
		stack->collection[0] = temp;
	}
	if (*op)
		ft_printf("%s\n", op);
}

int	reverse_rotate(t_stack *stack, char *op)
{
	int	temp;

	if (stack->top < 1)
		print_error("op ID: RR", stack->id);
	else
	{
		temp = stack->collection[0];
		ft_memmove(&stack->collection[0], &stack->collection[1], \
		stack->top * sizeof(int));
		stack->collection[stack->top] = temp;
	}
	if (*op)
		ft_printf("%s\n", op);
	return (1);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, "\0");
	rotate(stack_b, "\0");
	ft_printf("rr\n");
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, "\0");
	reverse_rotate(stack_b, "\0");
	ft_printf("rrr\n");
}
