/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aproximity_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:10:29 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/08 11:27:34 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	aproximity_sort(t_ps *ps)
{
	int	smallest_number_index;

	while (ps->a->top > 2)
	{
		smallest_number_index = smallest_stack_number_index(ps->a);
		if (smallest_number_index < ps->a->top / 2)
		{
			while ((smallest_number_index != ps->a->top) \
			&& reverse_rotate(ps->a, "rra"))
				smallest_number_index = smallest_stack_number_index(ps->a);
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
	tiny_sort(ps->a);
	while (ps->b->top >= 0)
		push(ps->b, ps->a, "pa");
}
