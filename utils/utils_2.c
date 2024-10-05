/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:09:40 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/05 14:51:57 by marcsilv         ###   ########.fr       */
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
	exit(0);
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
	else
		lazy_sort(ps);
}

void	check_repeated_numbers(char **matrix)
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
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
