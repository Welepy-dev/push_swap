/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hedge_cases_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:07:41 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/22 14:00:11 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hedge_cases.h"

void	validate_number_range(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		print_error();
}

void	check_duplicates(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = i + 1;
		while (matrix[j] != NULL)
		{
			if (ft_atoi_long(matrix[i]) == ft_atoi_long(matrix[j]))
				print_error();
			j++;
		}
		i++;
	}
}

void	check_letters(char **matrix)
{
	int	i;
	int	j;
	int	num_started;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		num_started = 0;
		while (matrix[i][j] != '\0')
		{
			if (ft_isdigit(matrix[i][j]))
				num_started = 1;
			else if (num_started && !ft_isdigit(matrix[i][j]))
				print_error();
			j++;
		}
		i++;
	}
}
