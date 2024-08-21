/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:51:26 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/03 15:45:52 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			i;

	if (ac == 2)
		matrix_init(&stack_a, &stack_b, av, ac);
	else
		allocator_init(&stack_a, &stack_b, ac, av);
	i = stack_a.capacity;
	while (i > 0)
		ft_printf("%d ", stack_a.collection[--i]);
	free(stack_a.collection);
	free(stack_b.collection);
	return (0);
}
