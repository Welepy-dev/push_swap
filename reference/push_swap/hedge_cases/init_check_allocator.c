/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_allocator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:30:58 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/04 12:32:18 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hedge_cases.h"

void	init_check_allocator(char **matrix)
{
	int		k;
	long	num;

	k = 0;
	while (matrix[k] != NULL)
	{
		validate_allocator_string(matrix[k]);
		check_letters(matrix);
		num = ft_atoi_long(matrix[k]);
		validate_number_range(num);
		k++;
	}
	check_duplicates(matrix);
}

void	validate_allocator_string(char *str)
{
	int	l;

	l = 0;
	if ((str[l] == '+' || str[l] == '-') && str[l + 1] == '\0')
	{
		ft_printf("Error 12\n");
		print_error();
	}
	while (str[l] != '\0')
	{
		if ((str[l] == '+' || str[l] == '-') && !ft_isdigit(str[l + 1]))
		{
			ft_printf("Error 13\n");
			print_error();
		}
		l++;
	}
}
