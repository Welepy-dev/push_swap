/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:15:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 19:55:11 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, char **av, int i, char id)
{
	stack->counter = 0;
	stack->top = -1;
	stack->capacity = i;
	stack->target_index = 0;
	stack->current_push_cost = 0;
	stack->current_median_index = 0;
	stack->current_cheapest_index = 0;
	stack->collection = (int *)malloc(i * sizeof(int));
	if (!stack->collection)
		print_error("While allocating", id, NULL);
	i = stack->capacity - 1;
	if (id == 'a')
	{
		while (i >= 0)
			insert(stack, ft_atoi((av[i--])));
		stack->id = 'A';
	}
	else
		stack->id = 'B';
}

void	init(t_ps *ps, char **av)
{
	int	i;

	i = ft_matrix_len(av);
	init_stack(ps->a, av, i, 'a');
	init_stack(ps->b, av, i, 'b');
}

/*
init_check_matrix(matrix);
*/