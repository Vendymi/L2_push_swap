/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:49:11 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:49:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate_up(t_top *stack_a, t_top *stack_b, int (*f)(t_top *, t_top *))
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	update_end(stack_b);
	while ((*f)(stack_a, stack_b) == 0)
	{
		rb(stack_b);
		i++;
	}
	while (j < i)
	{
		rrb(stack_b);
		j++;
	}
	return (i);
}

int	rotate_down(t_top *stack_a, t_top *stack_b, int (*f)(t_top *, t_top *))
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*f)(stack_a, stack_b) == 0)
	{
		rrb(stack_b);
		i++;
	}
	while (j < i)
	{
		rb(stack_b);
		j++;
	}
	return (i);
}

void	down(t_top *stack_a, t_top *stack_b, int i, int j)
{
	while (i < 0 && j < 0)
	{
		rrr_write(stack_a, stack_b);
		i++;
		j++;
	}
	while (i++ < 0)
		rrb_write(stack_b);
	while (j < 0)
	{
		rra_write(stack_a);
		j++;
	}
	while (j-- > 0)
		ra_write(stack_a);
}

void	up(t_top *stack_a, t_top *stack_b, int i, int j)
{
	while (i > 0 && j > 0)
	{
		rr_write(stack_a, stack_b);
		i--;
		j--;
	}
	while (i-- > 0)
		rb_write(stack_b);
	while (j < 0)
	{
		rra_write(stack_a);
		j++;
	}
	while (j > 0)
		ra_write(stack_a);
}

void	rotate(t_top *stack_a, t_top *stack_b, int i, int j)
{
	if (i < 0)
		down(stack_a, stack_b, i, j);
	else
		up(stack_a, stack_b, i, j);
}
