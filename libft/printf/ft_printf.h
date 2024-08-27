/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: :2024/05/29 19:23:04 by marcsilv          #+#    #+#            */
/*   Updated: 2024/08/23 14:18:51 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include "../../push_swap/sort/sort.h"
# include "../../push_swap/push_swap.h"
# include "../../push_swap/hedge_cases/hedge_cases.h"


# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <errno.h>
# include <ctype.h>

int		upper(unsigned int decimalNumber);
int		lower(unsigned int decimalNumber);
int		find_specifier(char myString, va_list args);
int		ft_printf(const char *myString, ...);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_unsigned(unsigned int n);
int		ft_num_len(unsigned int num);
int		ft_ptr_len(uintptr_t num);

char	*ft_uitoa(unsigned int n);

void	ft_put_ptr(uintptr_t num);

#endif
