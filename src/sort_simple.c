/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:10:36 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/23 01:20:46 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
void	short_sort(t_stack *stack)
{
	if (!is_sorted(stack))
	{
		//int d;
		//d=stack->stack[0];
		//printf("%d",d);
		//if stack 0 =6 kbr mn stack 1 or 2 =1 than swap operation --- so stack zero go to the top ;
		//---->324 swap 3 and 2 = 234 
		
		if ((stack->stack[0] > stack->stack[1])
			&& (stack->stack[0] > stack->stack[2]))
			swap(stack);
		else if ((stack->stack[0] < stack->stack[1])
			&& (stack->stack[0] < stack->stack[2])
			&& (stack->stack[2] > stack->stack[1]))
			//146--->641
		{
			//printf("%d-top-\n",stack->stack[2]);
			rotate(stack);
			swap(stack);
			//printf("%d--",stack->stack[2]);
		}
		else if ((stack->stack[0] < stack->stack[1])
			&& (stack->stack[0] < stack->stack[2]))
			reverse_rotate(stack);
		else if ((stack->stack[0] > stack->stack[1])
			&& (stack->stack[0] < stack->stack[2]))
			rotate(stack);
		else
		{
			swap(stack);
			rotate(stack);
		}
	}
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	small;

	while (stack_a->top > 2)
	{
		small = find_smaller(stack_a);
		if (stack_a->stack[stack_a->top - 1] == small)
			swap(stack_a);
		else if (stack_a->stack[stack_a->top - 2] == small)
		{
			rotate(stack_a);
			rotate(stack_a);
		}
		else if (stack_a->stack[1] == small)
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_a);
		}
		else if (stack_a->stack[0] == small)
			reverse_rotate(stack_a);
		push(stack_a, stack_b);
	}
	//short _sort i used already when i have only 3 numbers left and push
	short_sort(stack_a);
	push(stack_b, stack_a);
	if (stack_a->capacity == 5)
	//if it reach last one push it at end to b back stack a ;
		push(stack_b, stack_a);
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->capacity == 3)
		short_sort(stack_a);
	else if (stack_a->capacity <= 5)
		small_sort(stack_a, stack_b);
}
