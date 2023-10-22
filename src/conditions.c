/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:47:16 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:47:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cond1(t_top *stack_a, t_top *stack_b)
{
	int	top_b;
	int	end_b;
	int	top_a;
	int	max_b;
	int	min_b;

	top_b = stack_b->top->index;
	top_a = stack_a->top->index;
	end_b = stack_b->end->index;
	max_b = find_max_index(stack_b);
	min_b = find_min_index(stack_b);
	if (top_b < top_a && end_b > top_a)
		return (1);
	else if (top_a > max_b && max_b == top_b)
		return (1);
	else if (top_a < min_b && top_b == max_b)
		return (1);
	return (0);
}

int	cond2(t_top *stack_a, t_top *stack_b)
{
	int	top_b;
	int	max_b;
	int	end_a;
	int	end_b;

	if (stack_a->size != 0)
	{
		update_end(stack_a);
		end_a = stack_a->end->index;
	}
	top_b = stack_b->top->index;
	max_b = find_max_index(stack_b);
	end_b = stack_b->end->index;
	if (top_b == max_b)
		return (1);
	else if (stack_a->size != 0 && end_a + 1 == end_b)
		return (2);
	return (0);
}

int	cond3(t_top *stack_a, t_top *stack_b)
{
	int		min_b;
	int		end_a;
	int		right_a;

	min_b = find_min_index(stack_a);
	end_a = stack_b->end->index;
	right_a = min_b - 1;
	if (min_b == 0)
		return (1);
	else if (right_a == end_a)
		return (1);
	return (0);
}

int	cond4(t_top *stack_a, t_top *stack_b)
{
	if (stack_b->top->index == 0)
		return (1);
	if (stack_a->size != 0)
		write_error();
	return (0);
}
