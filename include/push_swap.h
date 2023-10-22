/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:49:06 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:49:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct t_stack
{
	int				data;
	int				index;
	struct t_stack	*prev;
	struct t_stack	*next;
}	t_stack;

typedef struct t_top
{
	int				size;
	struct t_stack	*top;
	struct t_stack	*end;
}	t_top;

/// Initialization and indexing
int		into_list(t_top *top, long data);
void	atoi_to_list(char *argv, t_top *top, int i);
void	arg_to_list(char **argv, t_top *top);
void	initialize_and_sort(char **argv);
void	to_index(t_top *top);

/// Sorting
void	sort_3(t_top *stack_a);
void	sort_5(t_top *stack_a);
void	sort(t_top *stack_a);
void	put_to_b_100(t_top *stack_a, t_top *stack_b);
void	put_to_b_500(t_top *stack_a, t_top *stack_b);
void	put_back_from_b(t_top *stack_a, t_top *stack_b);

/// Rotations
int		rotate_up(t_top *stack_a, t_top *stack_b, int (*f)(t_top *, t_top *));
int		rotate_down(t_top *stack_a, t_top *stack_b, int (*f)(t_top *, t_top *));
void	rotate(t_top *stack_a, t_top *stack_b, int i, int j);

/// Operations
void	update_end(t_top *stack);
void	sa(t_top *stack_a);
void	sb(t_top *stack_b);
void	ss(t_top *stack_a, t_top *stack_b);
void	pa(t_top *stack_a, t_top *stack_b);
void	pb(struct t_top *stack_a, struct t_top *stack_b);
void	ra(struct t_top *stack_a);
void	rb(t_top *stack_b);
void	rr(t_top *stack_a, t_top *stack_b);
void	rra(t_top *stack_a);
void	rrb(t_top *stack_b);
void	rrr(t_top *stack_a, t_top *stack_b);
void	sa_write(t_top *stack_a);
void	rra_write(t_top *stack_a);
void	ra_write(t_top *stack_a);
void	pb_write(t_top *stack_a, t_top *stack_b);
void	rrr_write(t_top *stack_a, t_top *stack_b);
void	rrb_write(t_top *stack_b);
void	rr_write(t_top *stack_a, t_top *stack_b);
void	rb_write(t_top *stack_b);
void	pa_write(t_top *stack_a, t_top *stack_b);

// Helping
int		max_index(t_top *stack);
int		find_max_index(t_top *stack);
int		find_min_index(t_top *stack);
int		put_in_b(t_top *stack_a, t_top *stack_b, int alim, int blim);
void	sort_a(t_top *stack_a, t_top *stack_b);
void	cleanup(t_top *top);
void	free_list(struct t_stack *stack_a);

/// Validation
int		is_sorted(t_top *stack_a);
int		check_validity(char c);
void	write_error(void);

// Condtions
int		cond1(t_top *stack_a, t_top *stack_b);
int		cond2(t_top *stack_a, t_top *stack_b);
int		cond3(t_top *stack_a, t_top *stack_b);
int		cond4(t_top *stack_a, t_top *stack_b);

/// Debugging
void	print_list(t_stack *stack_a);
void	print_list_and_index(t_stack *stack_a);

#endif