/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:47:38 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:47:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_validity(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == '-')
		return (1);
	return (0);
}

void	init_newnode(t_stack *newnode, int data)
{
	newnode->data = data;
	newnode->index = INT_MAX;
	newnode->prev = NULL;
	newnode->next = NULL;
}

int	into_list(t_top *top, long data)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (newnode == NULL || data > INT_MAX || data < INT_MIN)
	{
		free(newnode);
		write_error();
	}
	init_newnode(newnode, data);
	if (top->top == NULL)
	{
		top->top = newnode;
		top->end = newnode;
	}
	else
	{
		newnode->prev = top->end;
		top->end->next = newnode;
		top->end = newnode;
	}
	top->size++;
	return (1);
}

void	atoi_to_list(char *argv, t_top *top, int i)
{
	long	num;
	int		sign;

	while (argv[i] != '\0')
	{
		if (check_validity(argv[i]) == 0)
			write_error();
		num = 0;
		sign = 1;
		if (argv[i] == '-')
		{
			if (!(argv[++i] >= 48 && argv[i] <= 57))
				write_error();
			sign = -1;
		}
		while (argv[i] >= '0' && argv[i] <= '9')
		{
			num = num * 10 + argv[i++] - 48;
			if (argv[i] < '0' || argv[i] > '9')
				into_list(top, num * sign);
		}
		while (argv[i] == ' ')
			i++;
	}
}

void	arg_to_list(char **argv, t_top *top)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		atoi_to_list(argv[i], top, 0);
		i++;
	}
}
