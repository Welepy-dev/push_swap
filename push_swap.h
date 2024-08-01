/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:28:41 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/01 15:15:17 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/printf/ft_printf.h"
# include "./libft/libft.h"

# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
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
void	reverse_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_reverse_both(t_stack *stack_a, t_stack *stack_b);
void	allocator_init(t_stack *stack_a, t_stack *stack_b, int ac, char **av);

int		pop(t_stack *stack);
int		main(int ac, char **av);
int		swap(t_stack *stack, char *op);
int		push(t_stack *stack, int item, char *op);
int		swap_both(t_stack *stack_a, t_stack *stack_b);

#endif
