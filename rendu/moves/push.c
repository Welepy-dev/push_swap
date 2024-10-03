/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:41:20 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/03 18:45:24 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *src, t_stack *dst, char *op)
{
	if (is_empty(src))
		print_error("Source is empty. op ID: Push", src->id, NULL);
	if (is_full(dst))
		print_error("Destiny is full. op ID: Push", dst->id, NULL);
	dst->top++;
	dst->collection[dst->top] = src->collection[src->top];
	src->top--;
	if (*op)
		ft_printf("%s\n", op);
}

void	insert(t_stack *stack, int item)
{
	if (is_full(stack))
		print_error("Destiny is full. op ID: Insert", stack->id, NULL);
	stack->collection[++stack->top] = item;
}
