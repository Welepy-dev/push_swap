/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:09:40 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/01 19:18:57 by marcsilv         ###   ########.fr       */
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