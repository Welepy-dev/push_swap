/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:30:57 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/27 15:57:21 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	primediff;
	int	diff;
	int	i;
	int	k;

	push(stack_a, stack_b, "pa");	
	push(stack_a, stack_b, "pa");	

	i = stack_b->top;
	k = stack_b->top;
	primediff = 0;
	while (i >= -1)
	{
		if (stack_a->collection[k] > stack_b->collection[i])
			primediff = stack_a->collection[k] - stack_b->collection[i];
		if (primediff != 0)
			break;
		i--;
	}
	while (i >= -1)
	{
		if (stack_a->collection[k] > stack_b->collection[i])
			diff = stack_a->collection[k] - stack_b->collection[i];
		if (diff < primediff)
			primediff = diff;
		i--;
	}
	return (0);
}
