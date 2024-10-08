/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:52:09 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/08 15:25:52 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(char **matrix, char id)
{
	ft_printf("Error.\n");
	if (id)
		ft_matrix_free(matrix);
	exit(1);
}

bool	is_matrix_valid(char **matrix, char id)
{
	int		i;
	int		j;
	bool	is_valid;

	i = 0;
	is_valid = true;
	is_valid = check_repeated_numbers(matrix);
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			validate_number_range(ft_atoi_long(matrix[i]), matrix, id);
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
	return (is_valid);
}

void	validate_number_range(long num, char **matrix, char id)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_printf("Error\n");
		if (id)
			ft_matrix_free(matrix);
		exit(1);
	}
}
