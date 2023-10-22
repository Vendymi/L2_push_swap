/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_write.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:47:09 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:47:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb_write(t_top *stack_a, t_top *stack_b)
{
	pb(stack_a, stack_b);
	write(STDOUT_FILENO, "pb\n", 3);
}

void	rrr_write(t_top *stack_a, t_top *stack_b)
{
	rrr(stack_a, stack_b);
	write(STDOUT_FILENO, "rrr\n", 4);
}

void	rrb_write(t_top *stack_b)
{
	rrb(stack_b);
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	rb_write(t_top *stack_b)
{
	rb(stack_b);
	write(STDOUT_FILENO, "rb\n", 3);
}
