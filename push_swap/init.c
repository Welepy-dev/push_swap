/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:17:25 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/21 12:05:07 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	matrix_init(t_stack *stack_a, t_stack *stack_b, char **av, int ac)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = ft_split(av[1], ' ');
	while (matrix[i] != NULL)
		i++;
	stack_a->capacity = i;
	stack_b->capacity = i;
	stack_a->top = -1;
	stack_b->top = -1;
	stack_a->collection = (int *)malloc(i * sizeof(int));
	stack_b->collection = (int *)malloc(i * sizeof(int));
	if (!stack_a->collection || !stack_b->collection)
		print_error();
	init_hedge_cases(matrix);
	while (i > 0)
		insert(stack_a, ft_atoi((matrix[--i])));
	free(matrix);
}

void	allocator_init(t_stack *stack_a, t_stack *stack_b, int ac, char **av)
{
	int	i;

	i = ac - 1;
	stack_a->capacity = i;
	stack_b->capacity = i;
	stack_a->top = -1;
	stack_b->top = -1;
	stack_a->collection = (int *)malloc(stack_a->capacity * sizeof(int));
	stack_b->collection = (int *)malloc(stack_b->capacity * sizeof(int));
	if (stack_a->collection == NULL || stack_b->collection == NULL)
		print_error();
	init_hedge_cases(av);
	while (i > 0)
	{
		insert(stack_a, ft_atoi(av[i]));
		i--;
	}
}

void	init_hedge_cases(char **matrix)
{
	int	k;
	int	l;
	int	i;
	int	j;
	long	num;
	char *endptr;

	i = 0;
	k = 0;
	j = 0;
	while (matrix[k] != NULL)
	{
		l = 0;
		if ((matrix[k][l] == '+' || matrix[k][l] == '-') && matrix[k][l + 1] == '\0')
			print_error();
		while (matrix[k][l] != '\0')
		{
			if (!(ft_isdigit(matrix[k][l]) || matrix[k][l] == '+' || matrix[k][l] == '-'))
				print_error();
			if ((matrix[k][l] == '+' || matrix[k][l] == '-') && !ft_isdigit(matrix[k][l + 1]))
				print_error();
			l++;
		}
		num = ft_atoi_long(matrix[k]);
		if (num > INT_MAX || num < INT_MIN)
			print_error();
		k++;
	}
	while (matrix[i] != NULL)
	{
		j = i + 1;
		while (matrix[j] != NULL)
		{
			if (strtol(matrix[i], NULL, 10) == strtol(matrix[j], NULL, 10))
				print_error();
			j++;
		}
		i++;
	}
}

void	insert(t_stack *stack, int item)
{
	if (is_full(stack))
		print_error();
	stack->collection[++stack->top] = item;
}
