/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:09:40 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/10 14:20:10 by marcsilv         ###   ########.fr       */
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

void	print_error(char *error, char id)
{
	if (error)
		ft_printf("Error: %s Stack %c.\n", error, id);
	if (id == ' ')
		ft_printf("Invalid number\n");
	exit(1);
}

int	smallest_stack_number_index(t_stack *stack)
{
	int	i;
	int	smallest_number;
	int	smallest_number_index;

	i = 0;
	smallest_number = INT_MAX;
	smallest_number_index = 0;
	while (i <= stack->top)
	{
		if (stack->collection[i] < smallest_number)
		{
			smallest_number = stack->collection[i];
			smallest_number_index = i;
		}
		i++;
	}
	return (smallest_number_index);
}

void	choose_sort(t_ps *ps)
{
	if (ps->a->capacity == 2)
		swap(ps->a, "sa");
	else if (ps->a->capacity == 3)
		tiny_sort(ps->a);
	else if (ps->a->capacity <= 25)
		aproximity_sort(ps);
	else if (ps->a->capacity < 200)
		lazy_sort(ps, 5);
	else if (ps->a->capacity >= 200)
		lazy_sort(ps, 14);
}

bool	check_repeated_numbers(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = i + 1;
		while (matrix[j])
		{
			if (ft_atoi(matrix[i]) == ft_atoi(matrix[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
