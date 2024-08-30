/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:30:57 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/30 17:29:06 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	cheapest_operation_index;

	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	cheapest_operation_index = find_cheapest_operation_index(stack_a, stack_b);
}

void	send_to_b(t_stack *stack_a, t_stack *stack_b, int cheapest_operation_index)
{
	int	stack_a_steps_up;
	int	stack_a_steps_down;
	int	stack_b_steps_up;
	int	stack_b_steps_down;
	int	stack_b_index;

	stack_a_steps_up = 0;
	stack_a_steps_down = 0;
	stack_b_steps_up = 0;
	stack_b_steps_down = 0;
	if (stack_a->collection[cheapest_operation_index] == stack_a->collection[top])
	{
		//encontrar o numero da stack_b ideal e metelo no topo
		//depois meter o stack_a[top] na stack_b
		//fazer o resto com os outros 2 ifs
	}
	/*else if (cheapest_operation_index >= (stack_a->top / 2))
	{

	}
	else if (cheapest_operation_index < (stack_a->top / 2))
	{

	}*/
}

int	find_cheapest_operation_index(t_stack *stack_a, t_stack *stack_b)
{
	int	prime_cheapest;
	int	next_cheapest;
	int	cheapest_operation_index;
	int	k;

	k = stack_a->top;
	prime_cheapest = cost_of_operation(stack_a, stack_b, k);
	cheapest_operation_index = k;
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
	return (cheapest_operation_index);
}

int	cost_up_counter(t_stack *stack, int stack_number_index)
{
	int	steps_up;

	steps_up = 0;
	while (stack_number_index <= stack->top)
	{
		steps_up++;
		stack_number_index++;
	}
	return (steps_up);
}

int	cost_down_counter(t_stack *stack, int stack_number_index)
{
	int	steps_down;

	steps_down = 0;
	while (stack_number_index >= 0)
	{
		steps_down++;
		stack_number_index--;
	}
	return (steps_down);
}

int	cost_of_operation(t_stack *stack_a, t_stack *stack_b, int stack_a_index)
{
	int	placeholder;
	int	steps_up;
	int	steps_down;
	int	prime_cheapest;

	steps_up = 0;
	steps_down = 0;
	placeholder = find_placeholder(stack_a, stack_b, stack_a_index);
	if (placeholder >= stack_b->top / 2)
		steps_up = cost_up_counter(stack_b, placeholder);
	else
		steps_down = cost_down_counter(stack_b, placeholder);

	if (steps_up > steps_down)
		prime_cheapest = steps_up + (stack_a->top - stack_a_index + 1);
	else
		prime_cheapest = steps_down + (stack_a->top - stack_a_index + 1);
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
	return (placeholder);
}
