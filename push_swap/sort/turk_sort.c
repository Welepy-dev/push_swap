/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:30:57 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/29 16:34:53 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	prime_cheapest;
	int	last_cheapest;
	int	k;

	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	prime_cheapest = find_prime_cheapest(stack_a, stack_b);
}

int	find_prime_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int	placeholder;
	int	cost_up_counter;
	int	cost_down_counter;

	placeholder = find_placeholder(stack_a, stack_b);
	if (placeholder + 1 >= (stack_b->capacity / 2))
		while (placeholder <= stack_b->collection[top])
			cost_up_counter++;
	else if (placeholder + 1 < stack_b->capacity / 2)
	{
		while (placeholder >= 0)
		{
			cost_down_counter++;
			placeholder--;
		}
	}
	if (cost_up_counter > cost_down_counter)
		prime_cheapest = cost_up_counter + 1;
	else
		prime_cheapest = cost_down_counter + 1;
	return (prime_cheapest);
}

int	find_placeholder(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	prime_diff;
	int	diff;

	i = stack_b->top;
	while (i >= 0)
	{
		if (stack_a->collection[stack_a->top] > stack_b->collection[i])
			primediff = stack_a->collection[stack_a->top] - stack_b->collection[i];
		i--;
		if (primediff != 0)
			break ;
	}
	while (i >= 0)
	{
		if (stack_a->collection[stack_a->top] > stack_b->collection[i])
			diff = stack_a->collection[stack_a->top] - stack_b->collection[i];
		if (diff < primediff)
			placeholder = i;
		i--;
	}
	return (placeholder);
}
