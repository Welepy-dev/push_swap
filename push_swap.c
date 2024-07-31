/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:51:26 by marcsilv          #+#    #+#             */
/*   Updated: 2024/07/31 15:03:31 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			i, j;
	char	**matrix;

	if (ac == 2)
	{
		matrix = ft_split(av[1], ' ');
		i = 0;
		j = 0
		while (matrix[i] != NULL)
			i++;
		while (i > 0)
		{
			push(&stack_a, ft_atoi(matrix[i - 1]), "\0");
			i--;
		}
		while(matrix[j] != NULL)
		{
			free(matrix[j]);
			j++;
		}
	}
	else
	{
		i = ac - 1;
		stack_a.capacity = ac - 1;
		stack_b.capacity = ac - 1;
		stack_b.top = -1;
		stack_a.top = -1;
		stack_b.collection = (int *)malloc(stack_b.capacity * sizeof(int));
		stack_a.collection = (int *)malloc(stack_a.capacity * sizeof(int));
		if (stack_a.collection == NULL || stack_b.collection == NULL)
			printError();
		while (i > 0)
		{
			push(&stack_a, ft_atoi(av[i]), "\0");
			i--;
		}
	}
	printf("%d", stack_a.collection[stack_a.top]);
	free(stack_a.collection);
	free(stack_b.collection);
	return (0);
}
