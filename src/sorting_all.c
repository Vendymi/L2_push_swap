/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:49:37 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:49:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put_to_b_100(t_top *stack_a, t_top *stack_b)
{
	int	size;
	int	limit_below;
	int	limit;
	int	i;

	size = stack_a->size;
	limit = 25;
	limit_below = 0;
	i = 0;
	while (i < size)
	{
		while (i < limit && i < size)
		{
			if (limit > stack_a->size)
				limit = stack_a->size;
			put_in_b(stack_a, stack_b, limit_below, limit);
			i = limit;
		}
		put_back_from_b(stack_a, stack_b);
		limit += 25;
		limit_below += 25;
	}
	sort_a(stack_a, stack_b);
}

void	put_to_b_500(t_top *stack_a, t_top *stack_b)
{
	int	size;
	int	limit_below;
	int	limit;
	int	i;

	size = stack_a->size;
	limit = 90;
	limit_below = 0;
	i = 0;
	while (i < size)
	{
		while (i < limit && i < size)
		{
			if (limit > stack_a->size)
				limit = stack_a->size;
			put_in_b(stack_a, stack_b, limit_below, limit);
			i = limit;
		}
		put_back_from_b(stack_a, stack_b);
		limit_below = limit;
		limit += 60;
	}
	sort_a(stack_a, stack_b);
}

void	sort_all(t_top *stack_a)
{
	t_top	*stack_b;

	stack_b = (t_top *)malloc(sizeof(t_top));
	if (stack_b == NULL)
		exit (0);
	stack_b->top = NULL;
	stack_b->end = NULL;
	stack_b->size = 0;
	if (stack_a->size <= 100)
		put_to_b_100(stack_a, stack_b);
	else
		put_to_b_500(stack_a, stack_b);
	cleanup(stack_b);
}

void	sort(t_top *stack_a)
{
	if (stack_a->size == 0 || stack_a->size == 1)
		exit (0);
	if (is_sorted(stack_a))
		exit (0);
	else if (stack_a->size == 2)
	{
		write(1, "sa\n", 3);
		exit (0);
	}
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size <= 5)
		sort_5(stack_a);
	else
		sort_all(stack_a);
}
