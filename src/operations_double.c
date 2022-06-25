/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:51:11 by igvaz-fe          #+#    #+#             */
/*   Updated: 2021/10/30 17:11:18 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	holder_a;
	int	holder_b;

	holder_a = stack_a->stack[stack_a->top];
	stack_a->stack[stack_a->top] = stack_a->stack[stack_a->top - 1];
	stack_a->stack[stack_a->top - 1] = holder_a;
	holder_b = stack_b->stack[stack_b->top];
	stack_b->stack[stack_b->top] = stack_b->stack[stack_b->top - 1];
	stack_b->stack[stack_b->top - 1] = holder_b;
	write(1, "ss\n", 3);
}

void	double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int	holder_a;
	int	holder_top_a;
	int	holder_b;
	int	holder_top_b;

	holder_a = stack_a->stack[stack_a->top];
	holder_top_a = stack_a->top;
	while (holder_top_a > 0)
	{
		stack_a->stack[holder_top_a] = stack_a->stack[holder_top_a - 1];
		holder_top_a--;
	}
	stack_a->stack[holder_top_a] = holder_a;
	holder_b = stack_b->stack[stack_b->top];
	holder_top_b = stack_b->top;
	while (holder_top_b > 0)
	{
		stack_b->stack[holder_top_b] = stack_b->stack[holder_top_b - 1];
		holder_top_b--;
	}
	stack_b->stack[holder_top_b] = holder_b;
	write(1, "rr\n", 3);
}

void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int	holder_a;
	int	i;
	int	holder_b;
	int	j;

	i = 0;
	holder_a = stack_a->stack[i];
	while (i < stack_a->top)
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i++;
	}
	stack_a->stack[i] = holder_a;
	j = 0;
	holder_b = stack_b->stack[j];
	while (j < stack_b->top)
	{
		stack_b->stack[j] = stack_b->stack[j + 1];
		j++;
	}
	stack_b->stack[j] = holder_b;
	write(1, "rrr\n", 4);
}
