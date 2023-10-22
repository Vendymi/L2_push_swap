/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:47:34 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:47:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	to_index(t_top *top)
{
	int			i;
	int			num;
	t_stack		*tmp;
	t_stack		*iter;

	tmp = top->top;
	while (tmp)
	{
		iter = top->top;
		i = 0;
		num = tmp->data;
		while (iter)
		{
			if (num > iter->data)
				i++;
			if (num == iter->data && iter != tmp)
				write_error();
			iter = iter->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
	free_list(tmp);
	free_list(iter);
}
