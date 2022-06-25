/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:57:25 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/25 04:30:58 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_position(t_stack *stack_a, int moves, int value)
{
	int	i;

	i = 1;
	if (moves == 1)
		return (stack_a->top);
	while (i <= stack_a->top)
	{
		if (value < stack_a->stack[i - 1] && value > stack_a->stack[i])
			return (i - 1);
		i++;
	}
	return (i - 1);
}
//      2 5 7 12 15 20  25                          17  3 8 9
int	get_moves(t_stack *stack_a, int value)
{
	int	moves;
	int	half;
	int	top_a;

	moves = 0;
	half = stack_a->top / 2;
	top_a = stack_a->top;
	if (value < stack_a->stack[top_a] && value > stack_a->stack[0])
		return (1);
	top_a--;
	while (top_a >= half)
	{
		moves++;
		//8/{9}/10
		if (value < stack_a->stack[top_a] && value > stack_a->stack[top_a + 1])
			break ;
		top_a--;
	}
	//WHICH HASS LESS AND BEST MOVES FROM TOP A OR FROM THE END 
	while (top_a < half)
	{
		if (value < stack_a->stack[top_a] && value > stack_a->stack[top_a + 1])
			break ;
		moves--;
		top_a--;
	}
	return (moves + 1);
}

int	find_smaller(t_stack *stack)
{
	int	i;
	int	smaller;

	smaller = stack->stack[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->stack[i] < smaller)
			smaller = stack->stack[i];
		i++;
	}
	return (smaller);
}

int	find_higher(t_stack *stack)
{
	int	i;
	int	higher;

	higher = stack->stack[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->stack[i] > higher)
			higher = stack->stack[i];
		i++;
	}
	return (higher);
}
