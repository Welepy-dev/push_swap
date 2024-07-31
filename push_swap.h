/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:28:41 by marcsilv          #+#    #+#             */
/*   Updated: 2024/07/30 17:12:04 by marcsilv         ###   ########.fr       */
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

int		pop(t_stack *stack);
int		push(t_stack *stack, int item);

int 	push(t_stack, int item, char *op);
int	swap(t_stack *stack, char *op);
int	swap_both(t_stack *stack_a, t_stack *stack_b);

#endif
