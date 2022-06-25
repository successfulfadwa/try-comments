/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:10:39 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/26 00:09:24 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_movements(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	
// 17  20 25 2 5 7 12 15     //  3 8 9 
	int	next_top;

	next_top = stack_b->top - 1;
	while (stack_b->top != next_top)
	{
		if (idx_a >= stack_a->top / 2 && idx_b >= stack_b->top / 2)
			moves_one(stack_a, stack_b, idx_a, idx_b);
		else if (idx_a < stack_a->top / 2 && idx_b < stack_b->top / 2)
			moves_two(stack_a, stack_b, idx_a, idx_b);
		else if (idx_a >= stack_a->top / 2 && idx_b < stack_b->top / 2)
			moves_three(stack_a, stack_b, idx_a, idx_b);
		else if (idx_a < stack_a->top / 2 && idx_b >= stack_b->top / 2)
			moves_four(stack_a, stack_b, idx_a, idx_b);
	}
}
//      2 5 7 12 15 20  25                          17 3 8 9
void	send_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	moves;
	int	i;
	int	pos_b;
	
	i = stack_b->top + 1;
	pos_b = stack_b->top;//=0
	moves = stack_a->capacity * 2;
	//for both stacks to be able to carry them 
			// FOR CHECK BEST MOVES IN STACK A FOR EACH ELEMENT IN STACK B.
	while (--i >= 0) //i=0
	{
		if (i >= stack_b->top / 2 && get_moves(stack_a, stack_b->stack[i]) + stack_b->top - i < moves)
		{
			pos_b = i;
			moves = get_moves(stack_a, stack_b->stack[i]) + stack_b->top - i;
		}
		else if (i < stack_b->top / 2
			&& (get_moves(stack_a, stack_b->stack[i]) + (i + 1)) < moves)
		{
			pos_b = i;
			moves = get_moves(stack_a, stack_b->stack[i]) + (i + 1);
		}
	}
	i = get_position(stack_a, moves, stack_b->stack[pos_b]);// get position in a FOR B ELEMENTS
	do_movements(stack_a, stack_b, i, pos_b);
}
//,,,,,,,,,, 2 5 7 12 15 20 25  //  17 3 8 9 
void	 complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	smaller;
	int	higher;

	smaller = find_smaller(stack_a);
	higher = find_higher(stack_a);
	while (!is_sorted(stack_a))
	{
		//bayna if top ql mn befor last one and akbar mn  element at end  rotate  get all elements up by 1 o hadak first one li sghir ymshi loor/
		//second tryying .
		if ((stack_a->stack[stack_a->top] < stack_a->stack[stack_a->top - 1]
				&& stack_a->stack[stack_a->top] > stack_a->stack[0])
			|| stack_a->stack[stack_a->top] == smaller
			|| stack_a->stack[stack_a->top] == higher)
			rotate(stack_a);
		else
		{
			push(stack_a, stack_b);
			//printf("%d",stack_b->top);
		}
	}
	while (stack_b->top >= 0)
	{
	//hnaaa fooocuse 
		send_back_to_a(stack_a, stack_b);
	}
	while (!is_sorted(stack_a))
		moves_five(stack_a);
}
