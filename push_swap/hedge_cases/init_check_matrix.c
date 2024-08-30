/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:11:22 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/22 12:21:57 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hedge_cases.h"

void	init_check_matrix(char **matrix)
{
	int		k;
	long	num;

	k = 0;
	while (matrix[k] != NULL)
	{
		validate_matrix_string(matrix[k]);
		num = ft_atoi_long(matrix[k]);
		validate_number_range(num);
		k++;
	}
	check_duplicates(matrix);
}

void	validate_matrix_string(char *str)
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