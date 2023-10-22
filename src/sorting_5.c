/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:49:33 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:49:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate_index(t_top *stack_a)
{
	t_stack	*current;
	int		rotations;

	rotations = 0;
	current = stack_a->top;
	while (current->index != 0)
	{
		rotations += 1;
		current = current->next;
	}
	return (rotations);
}

void	order(t_top *stack_a)
{
	int		index;
	int		i;

	index = rotate_index(stack_a);
	i = 0;
	if (index <= stack_a->size - index)
	{
		while (i++ < index)
			ra_write(stack_a);
	}
	else
	{
		while (i++ < stack_a->size - index)
			rra_write(stack_a);
	}
}

void	put_to_b_5(t_top *stack_a, t_top *stack_b)
{
	while (stack_a->size > 3)
		pb_write(stack_a, stack_b);
}

void	put_back(t_top *stack_a, t_top *stack_b)
{
	while (1)
	{
		if (stack_a->top->index == find_min_index(stack_a) && \
				stack_b->top->index > find_max_index(stack_a))
			break ;
		else if (stack_b->top->index < stack_a->top->index && \
				stack_b->top->index > stack_a->end->index)
			break ;
		else if (stack_b->top->index < find_min_index(stack_a) \
				&& stack_a->end->index == find_max_index(stack_a))
			break ;
		else
			ra_write(stack_a);
	}
	pa_write(stack_a, stack_b);
}

void	sort_5(t_top *stack_a)
{
	t_top	*stack_b;

	stack_b = (t_top *)malloc(sizeof(t_top));
	if (stack_b == NULL)
		exit (0);
	stack_b->top = NULL;
	stack_b->end = NULL;
	stack_b->size = 0;
	put_to_b_5(stack_a, stack_b);
	sort_3(stack_a);
	while (stack_b->size > 0)
		put_back(stack_a, stack_b);
	order(stack_a);
	cleanup(stack_b);
}
