/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazy_aproximity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:53:10 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/05 15:09:10 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lazy_aproximity(t_ps *ps)
{
	int	smallest_number_index;

	while (ps->a->top >= 0)
	{
		smallest_number_index = smallest_stack_number_index(ps->a);
		if (smallest_number_index < ps->a->top / 2)
		{
			while (smallest_number_index != ps->a->top)
			{
				reverse_rotate(ps->a, "rra");
				smallest_number_index = smallest_stack_number_index(ps->a);
			}
		}
		else
		{
			while (smallest_number_index != ps->a->top)
			{
				rotate(ps->a, "ra");
				smallest_number_index = smallest_stack_number_index(ps->a);
			}
		}
		push(ps->a, ps->b, "pb");
	}
}

void	stack_it(t_ps *ps)
{
	int	highest_number_index;

	while (ps->b->top >= 0)
	{
		highest_number_index = highest_stack_number_index(ps->b);
		if (highest_number_index < ps->b->top / 2)
		{
			while (highest_number_index != ps->b->top)
			{
				reverse_rotate(ps->b, "rrb");
				highest_number_index = highest_stack_number_index(ps->b);
			}
		}
		else
		{
			while (highest_number_index != ps->b->top)
			{
				rotate(ps->b, "rb");
				highest_number_index = highest_stack_number_index(ps->b);
			}
		}
		push(ps->b, ps->a, "pa");
	}
}
