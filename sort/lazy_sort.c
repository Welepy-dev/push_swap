/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:10:29 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/10 14:13:47 by marcsilv         ###   ########.fr       */
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

void	lazy_sort_util(int *array, t_ps *ps)
{
	free(array);
	lazy_aproximity(ps);
	stack_it(ps);
}

void	lazy_sort_helper(int **array, t_ps *ps)
{
	*array = malloc(sizeof(int) * ps->a->capacity);
	ft_copy_array(*array, ps->a->collection, ps->a->capacity);
	bubble_sort(*array, ps->a->capacity);
}

void	lazy_sort(t_ps *ps, int flag)
{
	int	*array;
	int	ptr[3];

	ptr[1] = 0;
	lazy_sort_helper(&array, ps);
	ptr[0] = ps->a->top;
	while (++ptr[1] < flag)
	{
		ps->a->pivot = array[ptr[1] * ps->a->capacity / flag];
		while (--ptr[0] >= 0)
		{
			if ((ps->a->collection[ptr[0]] <= ps->a->pivot))
			{
				ptr[2] = ps->a->collection[ptr[0]];
				if (ptr[2] != ps->a->collection[ps->a->top])
					while (ptr[2] != ps->a->collection[ps->a->top])
						rotate(ps->a, "ra");
				while (ps->a->collection[ps->a->top] <= ps->a->pivot)
					push(ps->a, ps->b, "pb");
				ptr[0] = ps->a->top;
			}
		}
		ptr[0] = ps->a->top;
	}
	lazy_sort_util(array, ps);
}
