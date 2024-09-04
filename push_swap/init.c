/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:17:25 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/04 12:32:22 by marcsilv         ###   ########.fr       */
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
	{
		ft_printf("Error 1\n");
		print_error();
	}
	init_check_matrix(matrix);
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
	{
		ft_printf("Error 2\n");
		print_error();
	}
	init_check_allocator(av);
	while (i > 0)
	{
		insert(stack_a, ft_atoi(av[i]));
		i--;
	}
}
