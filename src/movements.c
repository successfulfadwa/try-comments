/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:53:21 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/25 23:25:49 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	moves_one(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	value_top_a;
	int	value_top_b;

	value_top_a = stack_a->stack[idx_a];
	value_top_b = stack_b->stack[idx_b];
	while (stack_a->stack[stack_a->top] != value_top_a
		&& stack_b->stack[stack_b->top] != value_top_b)
		double_rotate(stack_a, stack_b);
	while (stack_a->stack[stack_a->top] != value_top_a)
		rotate(stack_a);
	while (stack_b->stack[stack_b->top] != value_top_b)
		rotate(stack_b);
	push(stack_b, stack_a);
}

void	moves_two(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	value_top_a;
	int	value_top_b;

	value_top_a = stack_a->stack[idx_a];
	value_top_b = stack_b->stack[idx_b];
	while (stack_a->stack[stack_a->top] != value_top_a
		&& stack_b->stack[stack_b->top] != value_top_b)
		double_reverse_rotate(stack_a, stack_b);
	while (stack_a->stack[stack_a->top] != value_top_a)
		reverse_rotate(stack_a);
	while (stack_b->stack[stack_b->top] != value_top_b)
		reverse_rotate(stack_b);
	push(stack_b, stack_a);
}

void	moves_three(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	value_top_a;
	int	value_top_b;

	value_top_a = stack_a->stack[idx_a];
	value_top_b = stack_b->stack[idx_b];
	while (stack_a->stack[stack_a->top] != value_top_a)
		rotate(stack_a);
	while (stack_b->stack[stack_b->top] != value_top_b)
		reverse_rotate(stack_b);
	push(stack_b, stack_a);
}
// 17  20 25 2 5 7 12 15     // 17 3 8 9 
void	moves_four(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	value_top_a;
	int	value_top_b;

	value_top_a = stack_a->stack[idx_a];
	value_top_b = stack_b->stack[idx_b];
	while (stack_a->stack[stack_a->top] != value_top_a)
		reverse_rotate(stack_a);
	while (stack_b->stack[stack_b->top] != value_top_b)
		rotate(stack_b);
	push(stack_b, stack_a);
}

void	moves_five(t_stack *stack_a)
{
	int	higher;
	int	i;

	higher = find_higher(stack_a);
	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->stack[i] == higher)
			break ;
		i++;
	}
	if (i >= stack_a->top / 2)
		rotate(stack_a);
	else
		reverse_rotate(stack_a);
}
