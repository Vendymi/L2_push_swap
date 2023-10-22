/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all_helping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:49:22 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:49:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_in_b(t_top *stack_a, t_top *stack_b)
{
	int	i;

	if (rotate_up(stack_a, stack_b, cond1) >= \
			rotate_down(stack_a, stack_b, cond1))
		i = -rotate_down(stack_a, stack_b, cond1);
	else
		i = rotate_up(stack_a, stack_b, cond1);
	if (i < 0)
	{
		while (i++ < 0)
			rrb_write(stack_b);
	}
	else
	{
		while (i-- > 0)
			rb_write(stack_b);
	}
	pb_write(stack_a, stack_b);
}

int	put_in_b(t_top *stack_a, t_top *stack_b, int alim, int blim)
{
	t_stack		*tmp;
	int			i;

	i = blim - alim;
	tmp = stack_a->top;
	while (i > 0)
	{
		tmp = stack_a->top;
		if (tmp->index >= alim && tmp->index < blim)
		{
			if (i +2 > blim - alim)
				pb_write(stack_a, stack_b);
			else
				sort_in_b(stack_a, stack_b);
			i--;
		}
		else
			ra_write(stack_a);
	}
	return (blim - alim);
}

void	find_pos_in_a(t_top *stack_a, t_top *stack_b)
{
	int		i;
	int		j;

	if (rotate_up(stack_a, stack_b, cond2) >= \
			rotate_down(stack_a, stack_b, cond2))
		i = -rotate_down(stack_a, stack_b, cond2);
	else
		i = rotate_up(stack_a, stack_b, cond2);
	if (rotate_up(stack_a, stack_b, cond3) >= \
			rotate_down(stack_a, stack_b, cond3))
		j = -rotate_down(stack_b, stack_a, cond3);
	else
		j = rotate_up(stack_b, stack_a, cond3);
	rotate(stack_a, stack_b, i, j);
}

void	sort_a(t_top *stack_a, t_top *stack_b)
{
	int		i;

	if (rotate_up(stack_b, stack_a, cond4) >= \
			rotate_down(stack_b, stack_a, cond4))
	{
		i = -rotate_down(stack_b, stack_a, cond4);
	}
	else
	{
		i = rotate_up(stack_b, stack_a, cond4);
	}
	if (i < 0)
	{
		while (i++ < 0)
			rra_write(stack_a);
	}
	else
	{
		while (i-- > 0)
			ra_write(stack_a);
	}
}

void	put_back_from_b(t_top *stack_a, t_top *stack_b)
{
	if (stack_a->size != 0)
		find_pos_in_a(stack_a, stack_b);
	while (stack_b->size > 0)
		pa_write(stack_a, stack_b);
}
