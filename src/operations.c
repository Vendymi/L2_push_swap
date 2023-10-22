/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:48:41 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:48:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sb(t_top *stack_b)
{
	sa(stack_b);
}

void	ss(t_top *stack_a, t_top *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	rb(t_top *stack_b)
{
	ra(stack_b);
}

void	rr(t_top *stack_a, t_top *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
