/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:54:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 14:41:31 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_ps	ps;

	if (ac == 1 || (ac == 2 && !ft_strlen(av[1])))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ps.a = &a;
	ps.b = &b;
	if (ac == 2)
		init(&ps, av);
	else
		init(&ps, av + 1);
	//ft_matrix_free(av);		//HAVE TO DEAL WITH DOUBLE FREE ERROR
	if (!is_sorted(ps.a))
	{
		if (ps.a->capacity == 2)
			swap(ps.a, "sa");
		else if (ps.a->capacity == 3)
			tiny_sort(ps.a);
		// else
		// 	sort_stacks(&ps);
	}
	if (is_sorted(ps.a))
		ft_printf("   !!! STACK SORTED !!!\n");
	else if (!is_sorted(ps.a))
		ft_printf("  !!! STACK UNSORTED !!!\n");
	print_stacks(ps.a, ps.b);
	push_swap_free(&ps);
	return (0);
}
