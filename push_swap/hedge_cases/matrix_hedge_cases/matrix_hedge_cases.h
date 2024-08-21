/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_hedge_cases.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:16:38 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/21 15:25:53 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HEDGE_CASES_H
# define MATRIX_HEDGE_CASES_H

# include "../../push_swap.h"
# include "../../../libft/libft.h"
# include "../../../libft/printf/ft_printf.h"

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

void	validate_string(char *str);
void	init_check_matrix(char **matrix);
void	validate_number_range(long num);
void	check_duplicates(char **matrix);

#endif
