/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:47:29 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:47:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	max_index(t_top *stack)
{
	int			max;
	t_stack		*tmp;

	tmp = stack->top;
	max = INT_MIN;
	while (tmp)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_max_index(t_top *stack)
{
	int			max;
	t_stack		*tmp;

	max = -1;
	tmp = stack->top;
	while (tmp != NULL)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min_index(t_top *stack)
{
	int			min;
	t_stack		*tmp;

	min = INT_MAX;
	tmp = stack->top;
	while (tmp != NULL)
	{
		if (min > tmp->index)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}
