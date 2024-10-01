/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hedge_cases.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:09:31 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/01 19:18:57 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEDGE_CASES_H
# define HEDGE_CASES_H

# include "../../libft/libft.h"
# include "../../libft/ft_printf/ft_printf.h"
# include "../push_swap.h"

# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <errno.h>
# include <ctype.h>
# include <stdio.h>

void	validate_number_range(long num);
void	check_duplicates(char **matrix);
void	init_check_matrix(char **matrix);
void	validate_matrix_string(char *str);
void	init_check_allocator(char **matrix);
void	validate_allocator_string(char *str);
void	check_letters(char **matrix);

#endif
