/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:54:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 20:56:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**matrix;
	t_stack	a;
	t_stack	b;
	t_ps	ps;

	if (ac == 1 || (ac == 2 && !ft_strlen(av[1])))
		return (1);
	else if (ac == 2)
		matrix = ft_split(av[1], ' ');
	ps.a = &a;
	ps.b = &b;
	if (ac == 2)
		init(&ps, matrix);
	else
		init(&ps, av + 1);
	if (matrix != NULL)
		ft_matrix_free(matrix);
	if (!is_sorted(ps.a))
	{
		if (ps.a->capacity == 2)
			swap(ps.a, "sa");
		else if (ps.a->capacity == 3)
			tiny_sort(ps.a);
		else if (ps.a->capacity <= 10)
			aproximity_sort(&ps);
		else
			lazy_sort(&ps);
	}
	push_swap_free(&ps);
	return (0);
}
