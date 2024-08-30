/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:30:57 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/30 12:29:04 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	prime_cheapest;
	int	next_cheapest;
	int	cheapest_operation_index;
	int	k;

	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	k = stack_a->top;
	prime_cheapest = cost_of_operation(stack_a, stack_b, k);
	k--;
	while (k >= 0)
	{
		next_cheapest = cost_of_operation(stack_a, stack_b, k);
		if (next_cheapest < prime_cheapest)
		{
			prime_cheapest = next_cheapest;
			cheapest_operation_index = k;
		}
		k--;
	}

}

int	cost_of_operation(t_stack *stack_a, t_stack *stack_b, int stack_a_index)
{
	int	placeholder;
	int	cost_up_counter;									//maybe ill need these values later
	int	cost_down_counter;
	int	prime_cheapest;

	cost_up_counter = 0;
	cost_down_counter = 0;
	placeholder = find_placeholder(stack_a, stack_b, stack_a_index);
	if (placeholder + 1 >= stack_b->capacity / 2)
	{
		while (placeholder <= stack_b->top)
		{
			cost_up_counter++;
			placeholder++;
		}
	}
	else
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

int	find_placeholder(t_stack *stack_a, t_stack *stack_b, int stack_a_index)
{
	int	i;
	int	prime_diff;
	int	diff;
	int	placeholder;

	prime_diff = INT_MAX;
	diff = 0;
	placeholder = 0;
	i = stack_b->top;
	while (i >= 0)
	{
		if (stack_a->collection[stack_a_index] > stack_b->collection[i])
		{
			prime_diff = stack_a->collection[stack_a_index] - stack_b->collection[i];
			break ;
		}
		i--;
	}
	while (i >= 0)
	{
		if (stack_a->collection[stack_a_index] > stack_b->collection[i])
			diff = stack_a->collection[stack_a_index] - stack_b->collection[i];
		if (diff < prime_diff)
		{
			prime_diff = diff;
			placeholder = i;
		}
		i--;
	}
	return (placeholder);						//what if prime_diff is the smallest one
}
									//what if there is no numbers smaller than the one on stack_a
