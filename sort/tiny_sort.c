/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:04:22 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/04 15:50:13 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_stack *stack)
{
	int	highest_position;

	highest_position = highest_stack_number_index(stack);
	if (highest_position == 2)
		rotate(stack, "ra");
	else if (highest_position == 1)
		reverse_rotate(stack, "rra");
	if (stack->collection[2] > stack->collection[1])
		swap(stack, "sa");
}
