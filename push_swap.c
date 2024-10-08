/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:54:42 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/08 15:24:21 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_matrix(char **matrix, t_ps *ps)
{
	if (!is_matrix_valid(matrix, '\0'))
		error(matrix, '\0');
	init(ps, matrix);
	if (!is_sorted(ps->a))
		choose_sort(ps);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_ps	ps;
	char	**matrix;

	if (ac == 1 || (ac == 2 && (!ft_strlen(av[1]) || !ft_strcmp(av[1], " "))))
		error(NULL, '\0');
	ps.a = &a;
	ps.b = &b;
	if (ac == 2)
	{
		matrix = ft_split(av[1], ' ');
		if (!is_matrix_valid(matrix, 'm'))
			error(matrix, 'm');
		init(&ps, matrix);
		if (!is_sorted(ps.a))
			choose_sort(&ps);
		ft_matrix_free(matrix);
	}
	else
		init_matrix(av + 1, &ps);
	push_swap_free(&ps);
	return (0);
}
