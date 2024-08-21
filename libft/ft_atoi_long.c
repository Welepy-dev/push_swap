/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:18:05 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/21 15:24:04 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
