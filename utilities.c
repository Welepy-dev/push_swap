/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:28:12 by marcsilv          #+#    #+#             */
/*   Updated: 2024/07/31 15:00:42 by marcsilv         ###   ########.fr       */
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
		printError();
	return stack->collection[stack->top--];
}

void	printError(void)
{
	printf("Error: Not enough elements to swap\n");
        exit(1);
}
