/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:50:16 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/23 01:11:06 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack)
{
	int	holder;

	holder = stack->stack[stack->top];
	printf("%d",holder);
	stack->stack[stack->top] = stack->stack[stack->top - 1];
	stack->stack[stack->top - 1] = holder;
	write(1, "s", 1);
	write(1, &stack->c, 1);
	write(1, "\n", 1);
}
void	push(t_stack *stack_src, t_stack *stack_dst)
{
	// we use dst --> top -1 so we can turn it to zeroo hereeee...hehe yay
	stack_dst->top++;
	stack_dst->stack[stack_dst->top] = stack_src->stack[stack_src->top];
	stack_src->top--;
	write(1, "p", 1);
	write(1, &stack_dst->c, 1);
	write(1, "\n", 1);
}
//foq yhbt tht 
void	rotate(t_stack *stack)
{
	int	holder;
	int	holder_top;

	holder = stack->stack[stack->top];
	holder_top = stack->top;
	while (holder_top > 0)
	{
		stack->stack[holder_top] = stack->stack[holder_top - 1];
		holder_top--;
	}
	stack->stack[holder_top] = holder;

	write(1, "r", 1);
	write(1, &stack->c, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack *stack)
{
	int	holder;
	int	i;

	i = 0;
	holder = stack->stack[i];
	while (i < stack->top)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i] = holder;
	write(1, "rr", 2);
	write(1, &stack->c, 1);
	write(1, "\n", 1);
}
