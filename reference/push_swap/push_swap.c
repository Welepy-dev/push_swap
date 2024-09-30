/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:51:26 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/09 13:37:37 by marcsilv         ###   ########.fr       */
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
	
	ft_printf("==========================\n");
	ft_printf("\nInitial State\n");
	print_stacks(&stack_a, &stack_b);
	ft_printf("==========================\n");
	ft_printf("\noperations:\n\n");
	choose_sort(&stack_a, &stack_b);
	ft_printf("\n\n==========================\n");
	/*
	push(&stack_a, &stack_b, "pb");
	push(&stack_a, &stack_b, "pb");
	push(&stack_a, &stack_b, "pb");
	print_stacks(&stack_a, &stack_b);
	//functions_testers(&stack_a, &stack_b, i);
	rotate(&stack_a, "ra");
	rotate(&stack_b, "rb");
	rotate_both(&stack_a, &stack_b);
	print_stacks(&stack_a, &stack_b);
	reverse_rotate(&stack_a, "rra");
	reverse_rotate(&stack_b, "rrb");
	reverse_rotate_both(&stack_a, &stack_b);
	*/
	ft_printf("\nFinal output:\n");
	print_stacks(&stack_a, &stack_b);
	ft_printf("\n");
	free(stack_a.collection);
	free(stack_b.collection);
	return (0);
}

/*void	functions_testers(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	tempI = i;
	while (i > 5)
	{
		reverse_rotate_both(stack_a, stack_b);
		i--;
	}
}

/*void	functions_testers(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	tempI = i;
	while (i > 0)
	{
		push(stack_a, stack_b, "pb");
		i--;
	}
	print_stacks(stack_a, stack_b);
	while (i < tempI)
	{
		push(stack_b, stack_a, "pa");
		i++;
	}
	print_stacks(stack_a, stack_b);
	ft_printf("==========================\n\n");
	ft_printf("==========================\n\n");
}*/