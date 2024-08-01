/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:28:12 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/01 15:09:56 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_full(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

bool	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int	pop(t_stack *stack)
{
	if (is_empty(stack))
		print_error();
	return (stack->collection[stack->top--]);
}

void	print_error(void)
{
	ft_printf("Error.\n");
	exit(1);
}
