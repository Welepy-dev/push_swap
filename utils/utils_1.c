/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:46:37 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/04 16:19:28 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_full(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

bool	is_empty(t_stack *stack)
{
	return (stack->top < -1);
}

void	free_stack(t_stack *stack)
{
	free(stack->collection);
}

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->collection[i] < stack->collection[i + 1])
			return (false);
		i++;
	}
	return (true);
}

void	push_swap_free(t_ps *ps)
{
	free_stack(ps->a);
	free_stack(ps->b);
}
