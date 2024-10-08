/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:56:28 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/08 10:24:50 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_long(const char *nptr)
{
	int		count;
	long	numb;
	int		low;

	count = 0;
	low = 1;
	numb = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || (nptr[count] == 32))
		count++;
	if (nptr[count] == '+' || nptr[count] == '-')
	{
		if (nptr[count] == '-')
			low = -1;
		count++;
	}
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		numb = (10 * numb) + (nptr[count] - 48);
		count++;
	}
	return (numb * low);
}
