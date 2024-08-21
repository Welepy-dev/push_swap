/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:11:22 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/21 15:26:27 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_hedge_cases.h"

void	init_check_matrix(char **matrix)
{
	int		k;
	long	num;

	k = 0;
	while (matrix[k] != NULL)
	{
		validate_string(matrix[k]);
		num = ft_atoi_long(matrix[k]);
		validate_number_range(num);
		k++;
	}
	check_duplicates(matrix);
}

void	validate_string(char *str)
{
	int	l;

	l = 0;
	if ((str[l] == '+' || str[l] == '-') && str[l + 1] == '\0')
		print_error();
	while (str[l] != '\0')
	{
		if (!(ft_isdigit(str[l]) || str[l] == '+' || str[l] == '-'))
			print_error();
		if ((str[l] == '+' || str[l] == '-') && !ft_isdigit(str[l + 1]))
			print_error();
		l++;
	}
}

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
