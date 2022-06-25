/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:31:42 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/22 02:00:10 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int		capacity;
	int		top;
	int		*stack;
	char	c;
}	t_stack;

int		validate(char **argv);
void	swap(t_stack *stack);
void	push(t_stack *stack_src, t_stack *stack_dst);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	double_rotate(t_stack *stack_a, t_stack *stack_b);
void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	complex_sort(t_stack *stack_a, t_stack *stack_b);
int		is_b_sorted(t_stack *stack);
int		find_smaller(t_stack *stack);
int		find_higher(t_stack *stack);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
void	init_stack(t_stack *stack, char **argv);
t_stack	*create_stack(int capacity, char c);
int		get_moves(t_stack *stack_a, int value);
int		get_position(t_stack *stack_a, int moves, int value);
void	moves_one(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b);
void	moves_two(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b);
void	moves_three(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b);
void	moves_four(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b);
void	moves_five(t_stack *stack_a);

#endif
