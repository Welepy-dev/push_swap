/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:57:18 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/23 14:19:18 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./printf/ft_printf.h"
# include "../push_swap/push_swap.h"
# include "../push_swap/sort/sort.h"
# include "../push_swap/hedge_cases/hedge_cases.h"

# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <ctype.h>
# include <errno.h>

char	**ft_split(const char *s, char c);

void	*ft_memmove(void *dst, const void *src, size_t len);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_putchar(char c);
int		ft_putstr(char *c);
int		ft_putnbr(int n);
int		ft_isspace(int c);
int		ft_isalpha(int c);
int		ft_tolower(int c);
int		ft_isupper(int c);

long	ft_atoi_long(const char *str);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
#endif
