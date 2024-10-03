/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:09:40 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 19:17:12 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	highest_stack_number_index(t_stack *stack)
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

void	print_error(char *error, char id, t_ps *ps)
{
	if (error)
		ft_printf("Error: %s Stack %c.\n", error, id);
	exit(0);
}

int	smallest_stack_number_index(t_stack *stack)
{
	int	i;
	int	smallest_number;
	int	smallest_number_index;

	i = 0;
	smallest_number = INT_MAX;
	smallest_number_index = 0;
	while (i <= stack->top)
	{
		if (stack->collection[i] < smallest_number)
		{
			smallest_number = stack->collection[i];
			smallest_number_index = i;
		}
		i++;
	}
	return (smallest_number_index);
}

int	change_current_median_index(t_stack *stack)
{
	stack->current_median_index = ((stack->top + 1) / 2);
}

bool	is_above_median(t_stack *stack, int index)
{
	if (index >= stack->current_median_index)
		return (true);
	return (false);
}