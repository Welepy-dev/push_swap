/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:30:57 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/29 13:23:10 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	primediff;
	int	diff;
	int	placeholder;
	int	i;
	int	k;
	int	cost_up_counter;

	push(stack_a, stack_b, "pa");	
	push(stack_a, stack_b, "pa");	
	
	cost_up_counter = 0;
	i = stack_b->top;
	k = stack_b->top;
	primediff = 0;
	while (i >= 0)
	{
		if (stack_a->collection[k] > stack_b->collection[i])
			primediff = stack_a->collection[k] - stack_b->collection[i];
		i--;
		if (primediff != 0)
			break;
	}
	while (i >= 0)
	{
		if (stack_a->collection[k] > stack_b->collection[i])
			diff = stack_a->collection[k] - stack_b->collection[i];
		if (diff < primediff)
			placeholder = i;
		i--;
	}
	//cost_up
	while (placeholder <= stack->collection[top])
		cost_up_counter++;
	return (0);
}
