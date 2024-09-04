/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:51:26 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/04 17:49:07 by marcsilv         ###   ########.fr       */
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
	/*ft_printf("Stack A\n");
	while (i > 0)
		ft_printf("%d\n", stack_a.collection[--i]);*/
	choose_sort(&stack_a, &stack_b);
	ft_printf("\n");
	free(stack_a.collection);
	free(stack_b.collection);
	return (0);
}
