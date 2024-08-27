/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:28:41 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/23 14:20:55 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./sort/sort.h"
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "./hedge_cases/hedge_cases.h"


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

typedef struct stack
{
	int	*collection;
	int	capacity;
	int	top;
}	t_stack;

bool	sorted(void);
bool	both_sorted(void);
bool	is_full(t_stack *stack);
bool	is_empty(t_stack *stack);

void	print_error(void);
void	reverse(t_stack *stack_a, char *op);
void	matrix_init(t_stack *stack_a, t_stack *stack_b, char **av, int ac);
void	reverse_reverse(t_stack *stack_a, char *op);
void	insert(t_stack *stack, int item);
void	reverse_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_reverse_both(t_stack *stack_a, t_stack *stack_b);
void	allocator_init(t_stack *stack_a, t_stack *stack_b, int ac, char **av);
void	validate_string(char *str);
void	init_check_matrix(char **matrix);
void	init_check_allocator(char **matrix);
void	validate_number_range(long num);
void	check_duplicates(char **matrix);

int		pop(t_stack *stack);
int		main(int ac, char **av);
int		push(t_stack *src, t_stack *dst, char *op);
int		swap_both(t_stack *stack_a, t_stack *stack_b);

#endif
