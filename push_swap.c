/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:54:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/05 15:07:27 by marcsilv         ###   ########.fr       */
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
	{
		is_matrix_valid(av);
		init(&ps, av);
	}
	else
	{
		is_matrix_valid(av + 1);
		init(&ps, av + 1);
	}
	if (!is_sorted(ps.a))
		choose_sort(&ps);
	push_swap_free(&ps);
	return (0);
}