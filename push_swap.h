/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:28:58 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/05 14:58:58 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	char	id;
	int		top;
	int		capacity;
	int		*collection;
	int		pivo;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
}	t_ps;


void	stack_it(t_ps *ps);
void	lazy_sort(t_ps *ps);

bool	is_full(t_stack *stack);
bool	is_empty(t_stack *stack);

void	push_swap_free(t_ps *ps);

bool	is_sorted(t_stack *stack);

void	choose_sort(t_ps *ps);
void	tiny_sort(t_stack *stack);
void	aproximity_sort(t_ps *ps);
void	lazy_aproximity(t_ps *ps);
void	init(t_ps *ps, char **av);
void	free_stack(t_stack *stack);
void	swap(t_stack *stack, char *op);
void	is_matrix_valid(char **matrix);
void	validate_number_range(long num);
void	rotate(t_stack *stack, char *op);
void	insert(t_stack *stack, int item);
void	bubble_sort(int *array, int size);
void	print_error(char *error, char id);
void	check_repeated_numbers(char **matrix);
void	reverse_rotate(t_stack *stack, char *op);
void	push(t_stack *src, t_stack *dst, char *op);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);

int		highest_stack_number_index(t_stack *stack);
int		smallest_stack_number_index(t_stack *stack);

void	init_stack(t_stack *stack, char **av, int i, char id);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

#endif