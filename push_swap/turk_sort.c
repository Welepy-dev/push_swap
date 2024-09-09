/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:30:57 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/09 16:52:13 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	cheapest_operation_index;
	int	test_index;

	push(stack_a, stack_b, "pb");
	push(stack_a, stack_b, "pb");
	cheapest_operation_index = find_cheap_operation_index(stack_a, stack_b);
	while (stack_a->top >= 0)
	{
		a_to_b(stack_a, stack_b, cheapest_operation_index);
		cheapest_operation_index = find_cheap_operation_index(stack_a, stack_b);
		stack_a->top--;
	}
	test_index = stack_b->top;
	while (test_index >= 0)
	{
		ft_printf("%d\n", stack_b->collection[test_index]);
		test_index--;
	}
}*/

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	cheapest_operation_index;
	int	fake_top;

	push(stack_a, stack_b, "pb");
	push(stack_a, stack_b, "pb");

	fake_top = stack_a->top; // maybe delete later
	print_stacks(stack_a, stack_b);  // Debug output

	cheapest_operation_index = find_cheap_operation_index(stack_a, stack_b);
	ft_printf("Cheapest operation index: %d\n", cheapest_operation_index);  // Debug output
	/*while (fake_top >= 0)
	{
		ft_printf("Cheapest operation index: %d\n", cheapest_operation_index);  // Debug output
		a_to_b(stack_a, stack_b, cheapest_operation_index);
		cheapest_operation_index = find_cheap_operation_index(stack_a, stack_b);
		print_stacks(stack_a, stack_b);  // Debug output
		fake_top--;
	}*/

	/*test_index = stack_b->top;
	while (test_index >= 0)
	{
		ft_printf("%d\n", stack_b->collection[test_index]);
		test_index--;
	}*/
}

/*int	find_cheapest_operation_index(t_stack *stack_a, t_stack *stack_b)
{
	int	prime_cheapest;
	int	next_cheapest;
	int	cheapest_operation_index;
	int	k;

	k = stack_a->top;
	prime_cheapest = cost_of_operation(stack_a, stack_b, k);
	
}*/

// Paused here
// I need to find the cheapest operation index of the number on the stack_a to be sent on stack_b. but how to do it when is needed two indexes?


//use this function to find the cheapest index on each number from stack b
int	b_cheap_index(t_stack *stack_a, t_stack *stack_b, int stack_a_index)
{
	int stack_b_index;
	int first_difference;
	int next_difference;
}

// use this function to find the cheapest index on each number from stack a
int smallest_difference_index(t_stack *stack_a, t_stack *stack_b)
{
	int stack_a_counter;
	int stack_b_counter;
	int first_difference;
	int next_difference;
	int smallest_difference_index;

	stack_a_counter = stack_a->top;
	stack_b_counter = stack_b->top;
	first_difference = INT_MAX;
	while (stack_a_counter >= 0)
	{
		while (stack_b_counter >= 0)
		{
			next_difference = stack_a->collection[stack_a_counter] - stack_b->collection[stack_b_counter];
			if (next_difference < first_difference)
			{
				first_difference = next_difference;
				smallest_difference_index = stack_a_counter;
			}
			stack_b_counter--;
		}
		stack_a_counter--;
	}
	return (smallest_difference_index);
}



void	a_to_b(t_stack *stack_a, t_stack *stack_b, int cheap_index)
{
	int		stack_a_steps_up;
	int		stack_a_steps_down;
	int		stack_b_placeholder;
	char	*direction;

	stack_a_steps_up = 0;
	stack_a_steps_down = 0;
	if (stack_a->collection[cheap_index] == stack_a->collection[stack_a->top])
	{
		stack_b_placeholder = find_placeholder(stack_a, stack_b, stack_a->top);
		direction = find_direction(stack_b, stack_b_placeholder);
		if (ft_strcmp(direction, "up") == 0)
		{
			while (stack_b->top >= stack_b_placeholder)
			{
				rotate(stack_b, "rb");
				stack_b_placeholder++;
			}		
		}
		else if (ft_strcmp(direction, "down") == 0)
		{
			while (stack_b->top >= stack_b_placeholder)
			{
				reverse_rotate(stack_b, "rrb");
				stack_b_placeholder--;
			}
		}
		push(stack_a, stack_b, "pb");
	}
	else
	{
		stack_a_steps_up = cost_up_counter(stack_a, cheap_index);
		stack_a_steps_down = cost_down_counter(stack_a, cheap_index);
		if (stack_a_steps_up > stack_a_steps_down)
		{
			while (cheap_index <= stack_a->top)
			{
				rotate(stack_a, "ra");
				cheap_index++;
			}
		}
		else
		{
			while (cheap_index > 0)
			{
				reverse_rotate(stack_a, "rra");
				cheap_index--;
			}
		}
		push(stack_a, stack_b, "pb");
	}
}

/*int	find_cheap_operation_index(t_stack *stack_a, t_stack *stack_b)
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
}*/

/*int	find_cheap_operation_index(t_stack *stack_a, t_stack *stack_b)
{
	int	prime_cheapest;
	int	next_cheapest;
	int	cheapest_operation_index;
	int	k;

	k = stack_a->top;
	prime_cheapest = cost_of_operation(stack_a, stack_b, k); //hypothetical cost of the last operation
	cheapest_operation_index = k;
	k--;
	
	while (k >= 0)
	{
		next_cheapest = cost_of_operation(stack_a, stack_b, k);
		ft_printf("Comparing costs: %d (current cheapest) vs %d (next)\n", prime_cheapest, next_cheapest);  // Debug output
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
	return (steps_down + 1);
}

int	cost_of_operation(t_stack *stack_a, t_stack *stack_b, int s_a_index)
{
	int	placeholder;
	int	steps_up;
	int	steps_down;
	int	prime_cheapest;

	steps_up = 0;
	steps_down = 0;
	placeholder = find_placeholder(stack_a, stack_b, s_a_index);
	if (placeholder >= stack_b->top / 2)
		steps_up = cost_up_counter(stack_b, placeholder);
	else
		steps_down = cost_down_counter(stack_b, placeholder);
	if (steps_up > steps_down)
		prime_cheapest = steps_up + (stack_a->top - s_a_index + 1);
	else
		prime_cheapest = steps_down + (stack_a->top - s_a_index + 1);
	return (prime_cheapest);
}

int	find_placeholder(t_stack *stack_a, t_stack *stack_b, int s_a_index)
{
	int	i;
	int	prime_diff;
	int	diff;
	int	placeholder;

	prime_diff = INT_MAX;
	diff = 0;
	placeholder = 0;
	i = stack_b->top;
	while (i > 0)
	{
		if (stack_a->collection[s_a_index] > stack_b->collection[i])
		{
			prime_diff = stack_a->collection[s_a_index] - stack_b->collection[i];
			break ;
		}
		i--;
	}
	while (i > 0)
	{
		if (stack_a->collection[s_a_index] > stack_b->collection[i])
			diff = stack_a->collection[s_a_index] - stack_b->collection[i];
		if (diff < prime_diff)
		{
			prime_diff = diff;
			placeholder = i;
		}
		i--;
	}
	return (placeholder);
}

char	*find_direction(t_stack *stack, int number_position)
{
	char	*direction;

	if (number_position >= stack->top / 2)
		direction = "up";
	else
		direction = "down";
	return (direction);
}*/

void print_stacks(t_stack *stack_a, t_stack *stack_b) {
    int i;

    ft_printf("Stack A: ");
    for (i = stack_a->top; i >= 0; i--) {
        ft_printf("%d ", stack_a->collection[i]);
    }
    ft_printf("\nStack A current topmost number: %d\n", stack_a->collection[stack_a->top]);
    ft_printf("Stack A capacity: %d\n", stack_a->capacity);
    ft_printf("Stack A top index: %d\n", stack_a->top);
    ft_printf("\nStack B: ");
    for (i = stack_b->top; i >= 0; i--) {
        ft_printf("%d ", stack_b->collection[i]);
    }
    ft_printf("\nStack B current topmost number: %d\n", stack_b->collection[stack_b->top]);
    ft_printf("Stack B capacity: %d\n", stack_b->capacity);
    ft_printf("Stack B top index: %d\n", stack_b->top);
    ft_printf("\n");
}