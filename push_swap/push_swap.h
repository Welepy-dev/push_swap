/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:28:41 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/04 16:51:52 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void	rotate(t_stack *stack_a, char *op);
void	matrix_init(t_stack *stack_a, t_stack *stack_b, char **av, int ac);
void	reverse_rotate(t_stack *stack_a, char *op);
void	insert(t_stack *stack, int item);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_reverse_both(t_stack *stack_a, t_stack *stack_b);
void	allocator_init(t_stack *stack_a, t_stack *stack_b, int ac, char **av);
void	validate_string(char *str);
void	init_check_matrix(char **matrix);
void	init_check_allocator(char **matrix);
void	validate_number_range(long num);
void	check_duplicates(char **matrix);
void	tiny_sort(t_stack *stack, char stack_name);
void	turk_sort(t_stack *stack_a, t_stack *stack_b);
void	a_to_b(t_stack *stack_a, t_stack *stack_b, int cheap_index);
void	choose_sort(t_stack *stack_a, t_stack *stack_b);
void	super_tiny_sort(t_stack *stack, char stack_name);

int		find_cheap_operation_index(t_stack *stack_a, t_stack *stack_b);
int		cost_of_operation(t_stack *stack_a, t_stack *stack_b, int s_a_index);
int		cost_down_counter(t_stack *stack, int stack_number_index);
int		cost_up_counter(t_stack *stack, int stack_number_index);
int		find_placeholder(t_stack *stack_a, t_stack *stack_b, int s_a_index);
int		pop(t_stack *stack);
int		main(int ac, char **av);
int		push(t_stack *src, t_stack *dst, char *op);
int		swap_both(t_stack *stack_a, t_stack *stack_b);
int		highest_number_index(t_stack *stack);
int		swap(t_stack *stack, char *op);

char	*find_direction(t_stack *stack, int number_position);

#endif
