/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:10:29 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/04 16:18:12 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	lazy_sort(t_ps *ps)
{
	int	*array;
	int	i;
	int	j;
	int	l;

	j = 1;
	array = malloc(sizeof(int) * ps->a->capacity);
	ft_copy_array(array, ps->a->collection, ps->a->capacity);
	bubble_sort(array, ps->a->capacity);
	i = ps->a->top;
	while (j < 4)
	{
		ps->a->pivo = array[j * ps->a->capacity / 4];
		while (i >= 0)
		{
			if ((ps->a->collection[i] <= ps->a->pivo))
			{
				l = ps->a->collection[i];
				if (l != ps->a->collection[ps->a->top])
					while (l != ps->a->collection[ps->a->top])
						rotate(ps->a, "ra");
				push(ps->a, ps->b, "pb");
				i = ps->a->top;
			}
			i--;
		}
		i = ps->a->top;
		j++;
	}
	free(array);
	lazy_aproximity(ps);
	stack_it(ps);;
}
