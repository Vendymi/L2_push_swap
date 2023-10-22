/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_initiate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:48:36 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:48:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(struct t_stack *stack_a)
{
	struct t_stack	*curr;
	struct t_stack	*tmp;

	curr = stack_a;
	tmp = NULL;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

void	cleanup(t_top *top)
{
	free_list(top->top);
	free(top);
}

void	write_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit (0);
}

void	initialize_and_sort(char **argv)
{
	t_top	*top_a;

	top_a = (t_top *)malloc(sizeof(t_top));
	if (top_a == NULL)
	{
		free(top_a);
		write_error();
	}
	top_a->size = 0;
	top_a->top = NULL;
	arg_to_list(argv, top_a);
	to_index(top_a);
	sort(top_a);
	cleanup(top_a);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		write_error();
	if (argv[1][0] == '\0')
		write_error();
	initialize_and_sort(argv);
	return (0);
}
