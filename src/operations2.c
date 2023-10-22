/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:48:51 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:48:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_top *stack_a)
{
	t_stack	*top_a;
	t_stack	*prev;

	top_a = stack_a->top;
	if (top_a != NULL && top_a->next != NULL)
	{
		prev = NULL;
		while (top_a->next != NULL)
		{
			prev = top_a;
			top_a = top_a->next;
		}
		top_a->next = stack_a->top;
		stack_a->top = top_a;
		prev->next = NULL;
	}
	update_end(stack_a);
}

void	rrb(t_top *stack_b)
{
	rra(stack_b);
}

void	rrr(t_top *stack_a, t_top *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
