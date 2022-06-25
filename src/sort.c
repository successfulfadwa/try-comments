/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:55:38 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/23 23:48:47 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->capacity == 2)
		swap(stack_a);
	else if (stack_a->capacity <= 5)
		simple_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}
