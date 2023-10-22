/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:49:29 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:49:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_top *stack_a)
{
	t_stack	*current;

	current = stack_a->top;
	if (stack_a->size == 1)
		return (1);
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_3(t_top *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->top->data;
	b = stack_a->top->next->data;
	c = stack_a->top->next->next->data;
	if (b > a && b > c && c > a)
	{
		sa_write(stack_a);
		ra_write(stack_a);
	}
	else if (a > b && a < c && b < c)
		sa_write(stack_a);
	else if (a < b && a > c && b > c)
		rra_write(stack_a);
	else if (a > b && a > c && b > c)
	{
		sa_write(stack_a);
		rra_write(stack_a);
	}
	else if (a > b && a > c && b < c)
		ra_write(stack_a);
}
