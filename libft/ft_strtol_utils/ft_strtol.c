/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:38:22 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/08 16:47:19 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtol_utils.h"

int	ft_isspace(int c);
int	ft_isdigit(int c);
int	ft_isalpha(int c);
int	ft_isupper(int c);

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	const char 	*s;
	long			acc;
	long			cutoff;
	int			c;
	int			neg;
	int			any;
	int			cutlim;

	acc = 0;
	s = nptr;
	neg = 0;
	any = 0;
	while (ft_isspace((unsigned char) *s))
		s++;
	if (*s == '-')
	{
		neg = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	if ((base == 0 || base == 16) && *s == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		s += 2;
		base = 16;
	}
	else if (base == 0)
		base = (*s == '0') ? 8 : 10;
	if (neg)
		cutoff = LONG_MIN;
	else
		cutoff = LONG_MAX;
	cutlim = cutoff % base;
	cutoff /= base;
	if (neg)
	{
		if (cutlim > 0)
		{
			cutlim -= base;
			cutoff += 1;
		}
		cutlim = -cutlim;
	}
	while (1)
	{
		c = (unsigned char) *s++;
		if (ft_isdigit(c))
			c -= '0';
		else if (ft_isalpha(c))
			c -= ft_isupper(c) ? 'A' - 10 : 'a' - 10;
		else
			break;
		if (c >= base)
			break;
		if (any < 0)
			continue;
		if (neg)
		{
			if (acc < cutoff || (acc == cutoff && c > cutlim))
			{
				any = -1;
				acc = LONG_MIN;
				errno = ERANGE;
			}
			else
			{
				any = 1;
				acc *= base;
				acc -= c;
			}
		}
		else
		{
			if (acc > cutoff || (acc == cutoff && c > cutlim))
			{
				any = -1;
				acc = LONG_MAX;
				errno = ERANGE;
			}
			else
			{
				any = 1;
				acc *= base;
				acc += c;
			}
		}
	}
	if (endptr != NULL)
		*endptr = (char *) (any ? s - 1 : nptr);
	return acc;
}
