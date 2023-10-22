/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:48:47 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:48:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_end(t_top *stack)
{
	t_stack	*current;

	current = stack->top;
	while (current && current->next)
	{
		current = current->next;
	}
	stack->end = current;
}

void	sa(t_top *stack_a)
{
	t_stack	*top_a;
	int		temp;
	int		index;

	top_a = stack_a->top;
	if (top_a != NULL && top_a->next != NULL)
	{
		temp = top_a->data;
		index = top_a->index;
		top_a->data = top_a->next->data;
		top_a->next->data = temp;
		top_a->index = top_a->next->index;
		top_a->next->index = index;
	}
	update_end(stack_a);
}

void	pa(t_top *stack_a, t_top *stack_b)
{
	t_stack	*top_b;
	t_stack	*top_a;

	if (stack_b->top != NULL)
	{
		top_b = stack_b->top;
		stack_b->top = top_b->next;
		stack_b->size--;
		top_a = stack_a->top;
		if (top_a == NULL)
			top_b->next = NULL;
		else
			top_b->next = top_a;
		stack_a->top = top_b;
		stack_a->size++;
	}
	update_end(stack_a);
}

void	pb(struct t_top *stack_a, struct t_top *stack_b)
{
	t_stack	*top_a;

	if (stack_a->top == NULL)
		return ;
	top_a = stack_a->top;
	stack_a->top = stack_a->top->next;
	top_a->next = stack_b->top;
	stack_b->top = top_a;
	stack_a->size--;
	stack_b->size++;
	update_end(stack_a);
}

void	ra(struct t_top *stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	first = stack_a->top;
	second = first->next;
	while (first->next != NULL)
		first = first->next;
	first->next = stack_a->top;
	stack_a->top = second;
	first->next->next = NULL;
	update_end(stack_a);
}
