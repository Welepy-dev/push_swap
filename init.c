/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:15:01 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/10 14:13:47 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, char **av, int i, char id)
{
	stack->top = -1;
	stack->pivot = 0;
	stack->capacity = i;
	stack->collection = (int *)malloc(i * sizeof(int));
	if (!stack->collection)
		print_error("While allocating", id);
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
