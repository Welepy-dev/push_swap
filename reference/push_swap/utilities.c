/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:28:12 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/09 10:44:19 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_full(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

bool	is_empty(t_stack *stack)
{
	return (stack->top < -1);
}

int	pop(t_stack *stack)
{
	int	temp;

	temp = stack->collection[stack->top];
	stack->top--;
	if (is_empty(stack))
	{
		ft_printf("Error 8\n");
		print_error();
	}
	return (temp);
}

void	print_error(void)
{
	ft_printf("Error.\n");
	exit(1);
}

int	highest_number_index(t_stack *stack)
{
	int	i;
	int	highest_number;
	int	highest_number_index;

	i = 0;
	highest_number = INT_MIN;
	highest_number_index = 0;
	while (i <= stack->top)
	{
		if (stack->collection[i] > highest_number)
		{
			highest_number = stack->collection[i];
			highest_number_index = i;
		}
		i++;
	}
	return (highest_number_index);
}
