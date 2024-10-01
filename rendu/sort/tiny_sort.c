/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:04:22 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/01 19:49:28 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_stack *stack)
{
	int	highest_position;

	highest_position = highest_stack_number_index(stack);
	if (stack->collection[highest_position] == stack->collection[2])
		rotate(stack, "ra");
	else if (stack->collection[highest_position] == stack->collection[1])
		reverse_rotate(stack, "rra");
	if (stack->collection[2] > stack->collection[1])
		swap(stack, "sa");
}
// void	tiny_sort(t_stack *stack)
// {
// 	int	highest_position;

// 	highest_position = highest_stack_number_index(stack);

// 	// Debugging statement to ensure the operation is correct
// 	ft_printf("highest_position: %d\n", highest_position);
// 	ft_printf("Stack before tiny_sort: %d %d %d\n", stack->collection[0], stack->collection[1], stack->collection[2]);

// 	if (stack->collection[highest_position] == stack->collection[2])
// 	{
// 		ft_printf("Calling rotate (ra)\n");  // Debugging: print to check if rotate is called
// 		rotate(stack, "ra");
// 	}
// 	else if (stack->collection[highest_position] == stack->collection[1])
// 	{
// 		ft_printf("Calling reverse_rotate (rra)\n");  // Debugging: print to check if reverse_rotate is called
// 		reverse_rotate(stack, "rra");
// 	}
// 	if (stack->collection[2] > stack->collection[1])
// 	{
// 		ft_printf("Calling swap (sa)\n");  // Debugging: print to check if swap is called
// 		swap(stack, "sa");
// 	}

// 	// Debugging: print stack after sorting
// 	ft_printf("Stack after tiny_sort: %d %d %d\n", stack->collection[0], stack->collection[1], stack->collection[2]);
// }
