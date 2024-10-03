/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:28:58 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 20:49:18 by marcsilv         ###   ########.fr       */
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
	int		target_index;
	int		current_push_cost;
	int		current_median_index;
	int		current_cheapest_index;
	int		counter;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
}	t_ps;

int		highest_stack_number_index(t_stack *stack);
int		smallest_stack_number_index(t_stack *stack);

bool	is_full(t_stack *stack);
bool	is_empty(t_stack *stack);
bool	is_sorted(t_stack *stack);

void	aproximity_sort(t_ps *ps);
void	push_swap_free(t_ps *ps);
void	tiny_sort(t_stack *stack);
void	init(t_ps *ps, char **av);
void	free_stack(t_stack *stack);
void	swap(t_stack *stack, char *op);
void	rotate(t_stack *stack, char *op);
void	insert(t_stack *stack, int item);
void	reverse_rotate(t_stack *stack, char *op);
void	push(t_stack *src, t_stack *dst, char *op);
int	change_current_median_index(t_stack *stack);
void	print_error(char *error, char id, t_ps *ps);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
// void	print_stacks(t_stack *stack_a, t_stack *stack_b);		//delete later
void	init_stack(t_stack *stack, char **av, int i, char id);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

#endif