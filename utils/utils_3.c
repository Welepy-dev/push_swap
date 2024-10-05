/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:52:09 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/05 15:10:47 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_matrix_valid(char **matrix)
{
	int		i;
	int		j;
	bool	is_valid;

	i = 0;
	is_valid = true;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			validate_number_range(ft_atoi_long(matrix[i]));
			if (!ft_isdigit(matrix[i][j]) && \
			(matrix[i][j] != '-' && matrix[i][j] != '+'))
				is_valid = false;
			if ((matrix[i][j] == '-' || matrix[i][j] == '+') \
			&& !ft_isdigit(matrix[i][j + 1]))
				is_valid = false;
			j++;
		}
		i++;
	}
	check_repeated_numbers(matrix);
	if (!is_valid)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	validate_number_range(long num)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
