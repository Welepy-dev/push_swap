/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:26:10 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/04 17:01:51 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack *stack, char stack_name)
{
	int	highest_position;

	highest_position = highest_number_index(stack);
	if (stack_name == 'a')
	{
		if (stack->collection[highest_position] == stack->collection[2])
			rotate(stack, "ra");
		else if (stack->collection[highest_position] == stack->collection[1])
			reverse_rotate(stack, "rra");
		if (stack->collection[2] > stack->collection[1])
			swap(stack, "sa");
	}
	else if (stack_name == 'b')
	{
		if (stack->collection[highest_position] == stack->collection[0])
			reverse_rotate(stack, "rrb");
		else if (stack->collection[highest_position] == stack->collection[1])
			rotate(stack, "rb");
		if (stack->collection[0] > stack->collection[1])
		{
			rotate(stack, "rb");
			swap(stack, "sb");
			reverse_rotate(stack, "rrb");
		}
	}
}

void	super_tiny_sort(t_stack *stack, char stack_name)
{
	if (stack_name == 'a')
		if (stack->collection[1] > stack->collection[0])
			swap(stack, "sa");
	if (stack_name == 'b')
		if (stack->collection[0] > stack->collection[1])
			swap(stack, "sb");
}
