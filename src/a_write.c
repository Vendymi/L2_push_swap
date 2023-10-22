/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_write.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:46:52 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:46:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa_write(t_top *stack_a)
{
	sa(stack_a);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	pa_write(t_top *stack_a, t_top *stack_b)
{
	pa(stack_a, stack_b);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	ra_write(t_top *stack_a)
{
	ra(stack_a);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rra_write(t_top *stack_a)
{
	rra(stack_a);
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rr_write(t_top *stack_a, t_top *stack_b)
{
	rr(stack_a, stack_b);
	write(STDOUT_FILENO, "rr\n", 3);
}
